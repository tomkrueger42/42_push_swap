/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:22:20 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/16 13:55:38 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() parses through the src stack and then calls best_rotate() */
void efficient_rotation(struct s_node *lis_start, struct s_node *src,
	struct s_node *dst, struct s_head *head)
{
	struct s_rotation *r;

	r = ft_calloc(1, sizeof(struct s_rotation));
	if (r == NULL)
		free_exit("Error\n", EXIT_FAILURE, head);
	r->m_r_src = INT32_MAX;
	r->m_rr_src = INT32_MAX;
	r->m_x_src = INT32_MAX;
	while (r->r_src < lst_size(src))
	{
		if (part_of_lis(lis_start, src) == 0)
			set_rotations(r, src, dst);
		r->r_src++;
		src = src->next;
	}
	best_rotate(r, src, head);
	free(r);
}

/* This f() sets and saves the minimum amount of rotations */
void	set_rotations(struct s_rotation *r, struct s_node *src, struct s_node *dst)
{
	r->rr_src = r->r_src == 0 ? 0 : lst_size(src) - r->r_src;
	r->r_dst = find_right_position(src, dst);
	r->rr_dst = r->r_dst == 0 ? 0 : lst_size(dst) - r->r_dst;
	r->x_src = r->r_src < r->rr_src ? r->r_src : -r->rr_src;
	r->x_dst = r->r_dst < r->rr_dst ? r->r_dst : -r->rr_dst;

	if (MAX(r->r_src, r->r_dst) < MAX(r->m_r_src, r->m_r_dst))
	{
		r->m_r_src = r->r_src;
		r->m_r_dst = r->r_dst;
	}
	if (MAX(r->rr_src, r->rr_dst) < MAX(r->m_rr_src, r->m_rr_dst))
	{
		r->m_rr_src = r->rr_src;
		r->m_rr_dst = r->rr_dst;
	}
	if (ABS(r->x_src) + ABS(r->x_dst) < ABS(r->m_x_src) + ABS(r->m_x_dst))
	{
		r->m_x_src = r->x_src;
		r->m_x_dst = r->x_dst;
	}
}

/* This f() executes the best rotation and calls others when needed */
void	best_rotate(struct s_rotation *r, struct s_node *src, struct s_head *head)
{
	char	c;

	if (MAX(r->m_r_src, r->m_r_dst) > MAX(r->m_rr_src, r->m_rr_dst))
		return (best_revrotate(r, src, head));
	if (MAX(r->m_r_src, r->m_r_dst) > ABS(r->m_x_src) + ABS(r->m_x_dst))
		return (best_x_rotate(r, src, head));
	if (r->m_r_src > r->m_r_dst)
		c = src == head->a ? 'a' : 'b';
	else
		c = src == head->a ? 'b' : 'a';
	while (MIN(r->m_r_src, r->m_r_dst)> 0)
	{
		rotate('r', head);
		r->m_r_src--;
		r->m_r_dst--;
	}
	while (MAX(r->m_r_src, r->m_r_dst) > 0)
	{
		rotate(c, head);
		r->m_r_src--;
		r->m_r_dst--;
	}
}

/* This f() executes the best rev rotation and calls best_x_rotation when needed */
void	best_revrotate(struct s_rotation *r, struct s_node *src, struct s_head *head)
{
	char	c;

	if (MAX(r->m_rr_src, r->m_rr_dst) > ABS(r->m_x_src) + ABS(r->m_x_dst))
		return (best_x_rotate(r, src, head));
	if (r->m_rr_src > r->m_rr_dst)
		c = src == head->a ? 'a' : 'b';
	else
		c = src == head->a ? 'b' : 'a';
	while (MIN(r->m_rr_src, r->m_rr_dst) > 0)
	{
		revrotate('r', head);
		r->m_rr_src--;
		r->m_rr_dst--;
	}
	while (MAX(r->m_rr_src, r->m_rr_dst) > 0)
	{
		revrotate(c, head);
		r->m_rr_src--;
		r->m_rr_dst--;
	}
}

/* This f() executes the best cross-rotation */
void	best_x_rotate(struct s_rotation *r, struct s_node *src, struct s_head *head)
{
	char	c;

	c = src == head->a ? 'a' : 'b';
	while (r->m_x_src > 0)
	{
		rotate(c, head);
		r->m_x_src--;
	}
	while (r->m_x_src < 0)
	{
		revrotate(c, head);
		r->m_x_src++;
	}
	c = c == 'a' ? 'b' : 'a';
	while (r->m_x_dst > 0)
	{
		rotate(c, head);
		r->m_x_dst--;
	}
	while (r->m_x_dst < 0)
	{
		revrotate(c, head);
		r->m_x_dst++;
	}
}
