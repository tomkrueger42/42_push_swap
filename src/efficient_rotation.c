/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:22:20 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/21 17:21:23 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() parses through the s stack and then calls best_rotate() */
void	efficient_rotation(t_node *lis_start, t_node *s,
	t_node *d, t_head *head)
{
	t_rotation	*r;

	r = ft_calloc(1, sizeof(t_rotation));
	if (r == NULL)
		free_exit("Error\n", EXIT_FAILURE, head);
	r->m_r_s = INT32_MAX;
	r->m_rr_s = INT32_MAX;
	r->m_x_s = INT32_MAX;
	while (r->r_s < lst_size(s))
	{
		if (part_of_lis(lis_start, s) == 0)
			set_r(r, s, d);
		r->r_s++;
		s = s->next;
	}
	best_rotate(r, s, head);
	free(r);
}

/* This f() sets and saves the minimum amount of rotations */
void	set_r(t_rotation *r, t_node *s, t_node *d)
{
	r->rr_s = 0;
	if (r->r_s != 0)
		r->rr_s = lst_size(s) - r->r_s;
	r->r_d = find_right_position(s, d);
	r->rr_d = 0;
	if (r->r_d != 0)
		r->rr_d = lst_size(d) - r->r_d;
	if (r->r_s < r->rr_s)
		r->x_s = r->r_s;
	else
		r->x_s = -r->rr_s;
	if (r->r_d < r->rr_d)
		r->x_d = r->r_d;
	else
		r->x_d = -r->rr_d;
	if (ft_max(2, r->r_s, r->r_d) < ft_max(2, r->m_r_s, r->m_r_d))
	{
		r->m_r_s = r->r_s;
		r->m_r_d = r->r_d;
	}
	if (ft_max(2, r->rr_s, r->rr_d) < ft_max(2, r->m_rr_s, r->m_rr_d))
	{
		r->m_rr_s = r->rr_s;
		r->m_rr_d = r->rr_d;
	}
	if (ft_abs(r->x_s) + ft_abs(r->x_d) < ft_abs(r->m_x_s) + ft_abs(r->m_x_d))
	{
		r->m_x_s = r->x_s;
		r->m_x_d = r->x_d;
	}
}

/* This f() executes the best rotation and calls others when needed */
void	best_rotate(t_rotation *r, t_node *s, t_head *head)
{
	char	c;

	if (ft_max(2, r->m_r_s, r->m_r_d) > ft_max(2, r->m_rr_s, r->m_rr_d))
		return (best_revrotate(r, s, head));
	if (ft_max(2, r->m_r_s, r->m_r_d) > ft_abs(r->m_x_s) + ft_abs(r->m_x_d))
		return (best_x_rotate(r, s, head));
	if (r->m_r_s > r->m_r_d)
		c = s == head->a ? 'a' : 'b';
	else
		c = s == head->a ? 'b' : 'a';
	while (ft_min(2, r->m_r_s, r->m_r_d) > 0)
	{
		rotate('r', true, head);
		r->m_r_s--;
		r->m_r_d--;
	}
	while (ft_max(2, r->m_r_s, r->m_r_d) > 0)
	{
		rotate(c, true, head);
		r->m_r_s--;
		r->m_r_d--;
	}
}

/* This f() executes the best rev rotation and calls best_x_rotation when
needed */
void	best_revrotate(t_rotation *r, t_node *s, t_head *head)
{
	char	c;

	if (ft_max(2, r->m_rr_s, r->m_rr_d) > ft_abs(r->m_x_s) + ft_abs(r->m_x_d))
		return (best_x_rotate(r, s, head));
	if (r->m_rr_s > r->m_rr_d)
		c = s == head->a ? 'a' : 'b';
	else
		c = s == head->a ? 'b' : 'a';
	while (ft_min(2, r->m_rr_s, r->m_rr_d) > 0)
	{
		revrotate('r', true, head);
		r->m_rr_s--;
		r->m_rr_d--;
	}
	while (ft_max(2, r->m_rr_s, r->m_rr_d) > 0)
	{
		revrotate(c, true, head);
		r->m_rr_s--;
		r->m_rr_d--;
	}
}

/* This f() executes the best cross-rotation */
void	best_x_rotate(t_rotation *r, t_node *s, t_head *head)
{
	char	c;

	c = s == head->a ? 'a' : 'b';
	while (r->m_x_s > 0)
	{
		rotate(c, true, head);
		r->m_x_s--;
	}
	while (r->m_x_s < 0)
	{
		revrotate(c, true, head);
		r->m_x_s++;
	}
	c = c == 'a' ? 'b' : 'a';
	while (r->m_x_d > 0)
	{
		rotate(c, true, head);
		r->m_x_d--;
	}
	while (r->m_x_d < 0)
	{
		revrotate(c, true, head);
		r->m_x_d++;
	}
}
