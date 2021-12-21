/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:22:20 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/21 17:39:38 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() parses through the s stack and then calls best_rotate() */
void	efficient_rotation(t_node *lis_start, t_node *s,
	t_node *d, t_head *head)
{
	t_rotation	*r;
	t_rotation	*ben;

	r = ft_calloc(1, sizeof(t_rotation));
	if (r == NULL)
		free_exit("Error\n", EXIT_FAILURE, head);
	ben = ft_calloc(1, sizeof(t_rotation));
	if (ben == NULL)
	{
		free(r);
		free_exit("Error\n", EXIT_FAILURE, head);
	}
	ben->r_s = INT32_MAX;
	ben->rr_s = INT32_MAX;
	ben->x_s = INT32_MAX;
	while (r->r_s < lst_size(s))
	{
		if (part_of_lis(lis_start, s) == 0)
			set_r(r, ben, s, d);
		r->r_s++;
		s = s->next;
	}
	best_rotate(ben, s, head);
	free(r);
	free(ben);
}

/* This f() sets and saves the minimum amount of rotations */
void	set_r(t_rotation *r, t_rotation *ben, t_node *s, t_node *d)
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
	benchmark(r, ben);
}

void	benchmark(t_rotation *r, t_rotation *ben)
{
	if (ft_max(2, r->r_s, r->r_d) < ft_max(2, ben->r_s, ben->r_d))
	{
		ben->r_s = r->r_s;
		ben->r_d = r->r_d;
	}
	if (ft_max(2, r->rr_s, r->rr_d) < ft_max(2, ben->rr_s, ben->rr_d))
	{
		ben->rr_s = r->rr_s;
		ben->rr_d = r->rr_d;
	}
	if (ft_abs(r->x_s) + ft_abs(r->x_d) < ft_abs(ben->x_s) + ft_abs(ben->x_d))
	{
		ben->x_s = r->x_s;
		ben->x_d = r->x_d;
	}
}

/* This f() executes the best rotation and calls others when needed */
void	best_rotate(t_rotation *ben, t_node *s, t_head *head)
{
	char	c;

	if (ft_max(2, ben->r_s, ben->r_d) > ft_max(2, ben->rr_s, ben->rr_d))
		return (best_revrotate(ben, s, head));
	if (ft_max(2, ben->r_s, ben->r_d) > ft_abs(ben->x_s) + ft_abs(ben->x_d))
		return (best_x_rotate(ben, s, head));
	if (ben->r_s > ben->r_d)
		c = s == head->a ? 'a' : 'b';
	else
		c = s == head->a ? 'b' : 'a';
	while (ft_min(2, ben->r_s, ben->r_d) > 0)
	{
		rotate('r', true, head);
		ben->r_s--;
		ben->r_d--;
	}
	while (ft_max(2, ben->r_s, ben->r_d) > 0)
	{
		rotate(c, true, head);
		ben->r_s--;
		ben->r_d--;
	}
}

/* This f() executes the best rev rotation and calls best_x_rotation when
needed */
void	best_revrotate(t_rotation *ben, t_node *s, t_head *head)
{
	char	c;

	if (ft_max(2, ben->rr_s, ben->rr_d) > ft_abs(ben->x_s) + ft_abs(ben->x_d))
		return (best_x_rotate(ben, s, head));
	if (ben->rr_s > ben->rr_d)
		c = s == head->a ? 'a' : 'b';
	else
		c = s == head->a ? 'b' : 'a';
	while (ft_min(2, ben->rr_s, ben->rr_d) > 0)
	{
		revrotate('r', true, head);
		ben->rr_s--;
		ben->rr_d--;
	}
	while (ft_max(2, ben->rr_s, ben->rr_d) > 0)
	{
		revrotate(c, true, head);
		ben->rr_s--;
		ben->rr_d--;
	}
}

/* This f() executes the best cross-rotation */
void	best_x_rotate(t_rotation *ben, t_node *s, t_head *head)
{
	char	c;

	c = s == head->a ? 'a' : 'b';
	while (ben->x_s > 0)
	{
		rotate(c, true, head);
		ben->x_s--;
	}
	while (ben->x_s < 0)
	{
		revrotate(c, true, head);
		ben->x_s++;
	}
	c = c == 'a' ? 'b' : 'a';
	while (ben->x_d > 0)
	{
		rotate(c, true, head);
		ben->x_d--;
	}
	while (ben->x_d < 0)
	{
		revrotate(c, true, head);
		ben->x_d++;
	}
}
