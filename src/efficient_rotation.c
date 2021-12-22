/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:22:20 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/22 01:05:15 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() parses through the s stack and then calls best_rotate() */
void	efficient_rotation(t_node *lis_start, t_node *src,
	t_node *dst, t_head *head)
{
	t_rotation	*r;
	t_rotation	*bench;

	r = ft_calloc(1, sizeof(t_rotation));
	if (r == NULL)
		free_exit("Error\n", EXIT_FAILURE, head, NULL);
	bench = ft_calloc(1, sizeof(t_rotation));
	if (bench == NULL)
		free_exit("Error\n", EXIT_FAILURE, head, r);
	bench->src = INT32_MAX;
	bench->dst = INT32_MAX;
	while (r->pos < lst_size(src))
	{
		if (part_of_lis(lis_start, src) == 0)
			calc_r(r, bench, src, dst);
		r->pos++;
		src = src->next;
	}
	if (src == head->a)
		best_rotate(bench, 'a', 'b', head);
	else if (src == head->b)
		best_rotate(bench, 'b', 'a', head);
	free(r);
	free(bench);
}

/* This f() calc and saves the minimum amount of rotations */
void	calc_r(t_rotation *r, t_rotation *bench, t_node *src, t_node *dst)
{
	int	rota_src;
	int	rota_dst;
	int	revrota_src;
	int	revrota_dst;

	rota_src = r->pos;
	rota_dst = find_right_position(src, dst);
	revrota_src = lst_size(src) - rota_src;
	revrota_dst = lst_size(dst) - rota_dst;
	if (ft_max(2, rota_src, rota_dst) < ft_max(2, revrota_src, revrota_dst))
	{
		set_r(r, rota_src, rota_dst, false);
	}
	else
	{
		set_r(r, -revrota_src, -revrota_dst, false);
	}
	if (rota_src + revrota_dst < ft_max(2, ft_abs(r->src), ft_abs(r->dst)))
		set_r(r, rota_src, -revrota_dst, true);
	if (revrota_src + rota_dst < ft_max(2, ft_abs(r->src), ft_abs(r->dst)))
		set_r(r, -revrota_src, rota_dst, true);
	benchmark(r, bench);
}

/* This f() sets r's values */
void	set_r(t_rotation *r, int r_src, int r_dst, bool r_x)
{
	r->src = r_src;
	r->dst = r_dst;
	r->x = r_x;
}

/* This f() benchmarks the values of r and saves them accordingly */
void	benchmark(t_rotation *r, t_rotation *bench)
{
	if (r->x == false && bench->x == false && ft_max(2, ft_abs(r->src),
			ft_abs(r->dst)) < ft_max(2, ft_abs(bench->src), ft_abs(bench->dst)))
	{
		bench->x = false;
	}
	else if (r->x == false && bench->x == true && ft_max(2, ft_abs(r->src),
			ft_abs(r->dst)) < ft_abs(bench->src) + ft_abs(bench->dst))
	{
		bench->x = false;
	}
	else if (r->x == true && bench->x == false
		&& ft_abs(r->src) + ft_abs(r->dst)
		< ft_max(2, ft_abs(bench->src), ft_abs(bench->dst)))
	{
		bench->x = true;
	}
	else if (r->x == true && bench->x == true && ft_abs(r->src) + ft_abs(r->dst)
		< ft_abs(bench->src) + ft_abs(bench->dst))
	{
		bench->x = true;
	}
	else
		return ;
	bench->src = r->src;
	bench->dst = r->dst;
}

/* This f() executes the final benchmarks rotations */
void	best_rotate(t_rotation *bench, char src, char dst, t_head *head)
{
	while (bench->x == false && ft_min(2, bench->src, bench->dst) > 0)
	{
		rotate('r', true, head);
		bench->src--;
		bench->dst--;
	}
	while (bench->x == false && ft_min(2, bench->src, bench->dst) < 0)
	{
		revrotate('r', true, head);
		bench->src++;
		bench->dst++;
	}
	while (bench->src > 0 && bench->src--)
		rotate(src, true, head);
	while (bench->dst > 0 && bench->dst--)
		rotate(dst, true, head);
	while (bench->src < 0 && bench->src++)
		revrotate(src, true, head);
	while (bench->dst < 0 && bench->dst++)
		revrotate(dst, true, head);
}
