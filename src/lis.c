/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/15 19:55:37 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function finds the longest increasing sub-sequence in stack a and isolates that with push_sorted() */
void lis(struct s_head *head)
{
	struct s_node *parser;
	struct s_node *lis_start;
	int lis_len;
	int i;

	lis_len = 0;
	while (lst_size(head->a) > lis_len)
	{
		parser = head->a;
		i = 0;
		while (parser != head->a || i++ == 0)
		{
			if (lis_len < increasing_subsequence(parser))
			{
				lis_len = increasing_subsequence(parser);
				lis_start = parser;
			}
			parser = parser->next;
		}
		efficient_rotation(lis_start, head->a, head->b, head);
		push('b', head);
	}
}

void efficient_rotation(struct s_node *lis_start, struct s_node *src, struct s_node *dst, struct s_head *head)
{
	struct s_rotation *rollercoaster;

	rollercoaster = ft_calloc(1, sizeof(struct s_rotation));
	if (rollercoaster == NULL)
		free_exit("Error\n", EXIT_FAILURE, head);
	rollercoaster->best_delta = INT32_MAX;
	rollercoaster->best_rev_delta = INT32_MAX;
	rollercoaster->best_x_src = INT32_MAX;
	while (rollercoaster->rotate_src < lst_size(src))
	{
		if (part_of_lis(lis_start, src) == 0)
		{
			set_rotations(rollercoaster, src, dst);
			benchmark_rotations(rollercoaster);
		}
		rollercoaster->rotate_src++;
		src = src->next;
	}
	rock_n_roll(rollercoaster, src, head);
	free(rollercoaster);
}

void	set_rotations(struct s_rotation *rollercoaster, struct s_node *src, struct s_node *dst)
{
	rollercoaster->rev_rotate_src = rollercoaster->rotate_src == 0 ? 0 : lst_size(src) - rollercoaster->rotate_src;
	rollercoaster->rotate_dst = find_right_position(src, dst);
	rollercoaster->rev_rotate_dst = rollercoaster->rotate_dst == 0 ? 0 : lst_size(dst) - rollercoaster->rotate_dst;
	rollercoaster->x_src = rollercoaster->rotate_src < rollercoaster->rev_rotate_src ? rollercoaster->rotate_src : -rollercoaster->rev_rotate_src;
	rollercoaster->x_dst = rollercoaster->rotate_dst < rollercoaster->rev_rotate_dst ? rollercoaster->rotate_dst : -rollercoaster->rev_rotate_dst;
	rollercoaster->rotate_all = MIN(rollercoaster->rotate_src, rollercoaster->rotate_dst);
	rollercoaster->rev_rotate_all = MIN(rollercoaster->rev_rotate_src, rollercoaster->rev_rotate_dst);
	rollercoaster->delta = DIFF(rollercoaster->rotate_src, rollercoaster->rotate_dst);
	rollercoaster->rev_delta = DIFF(rollercoaster->rev_rotate_src, rollercoaster->rev_rotate_dst);
}

void benchmark_rotations(struct s_rotation *rollercoaster)
{
	if (rollercoaster->rotate_all + rollercoaster->delta < rollercoaster->best_rotate_all + rollercoaster->best_delta)
	{
		rollercoaster->best_rotate_src = rollercoaster->rotate_src;
		rollercoaster->best_rotate_dst = rollercoaster->rotate_dst;
		rollercoaster->best_rotate_all = rollercoaster->rotate_all;
		rollercoaster->best_delta = rollercoaster->delta;
	}
	if (rollercoaster->rev_rotate_all + rollercoaster->rev_delta < rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta)
	{
		rollercoaster->best_rev_rotate_src = rollercoaster->rev_rotate_src;
		rollercoaster->best_rev_rotate_dst = rollercoaster->rev_rotate_dst;
		rollercoaster->best_rev_rotate_all = rollercoaster->rev_rotate_all;
		rollercoaster->best_rev_delta = rollercoaster->rev_delta;
	}
	if (ABS(rollercoaster->x_src) + ABS(rollercoaster->x_dst) < ABS(rollercoaster->best_x_src) + ABS(rollercoaster->best_x_dst))
	{
		rollercoaster->best_x_src = rollercoaster->x_src;
		rollercoaster->best_x_dst = rollercoaster->x_dst;
	}
}

void rock_n_roll(struct s_rotation *rollercoaster, struct s_node *src, struct s_head *head)
{
	char	c;

	
	if (rollercoaster->best_rotate_all + rollercoaster->best_delta <= rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta
		&& rollercoaster->best_rotate_all + rollercoaster->best_delta <= ABS(rollercoaster->best_x_src) + ABS(rollercoaster->best_x_dst))
	{
		if (rollercoaster->best_rotate_src > rollercoaster->best_rotate_dst)
			c = src == head->a ? 'a' : 'b';
		else
			c = src == head->a ? 'b' : 'a';
		while (rollercoaster->best_rotate_all-- > 0)
			rotate('r', head);
		while (rollercoaster->best_delta-- > 0)
			rotate(c, head);
	}
	else if (rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta <= ABS(rollercoaster->best_x_src) + ABS(rollercoaster->best_x_dst))
	{
		if (rollercoaster->best_rev_rotate_src > rollercoaster->best_rev_rotate_dst)
			c = src == head->a ? 'a' : 'b';
		else
			c = src == head->a ? 'b' : 'a';
		while (rollercoaster->best_rev_rotate_all-- > 0)
			revrotate('r', head);
		while (rollercoaster->best_rev_delta-- > 0)
			revrotate(c, head);
	}
	else
	{
		c = src == head->a ? 'a' : 'b';
		while (rollercoaster->best_x_src > 0 && rollercoaster->best_x_src--)
			rotate(c, head);
		while (rollercoaster->best_x_src < 0 && rollercoaster->best_x_src++)
			revrotate(c, head);
		c = c == 'a' ? 'b' : 'a';
		while (rollercoaster->best_x_dst > 0 && rollercoaster->best_x_dst--)
			rotate(c, head);
		while (rollercoaster->best_x_dst < 0 && rollercoaster->best_x_dst++)
			revrotate(c, head);
	}
}

/* This function returns the length of an increasing subsequence */
int increasing_subsequence(struct s_node *lis_start)
{
	struct s_node *parser;
	int benchmark;
	int i;

	parser = lis_start->next;
	benchmark = lis_start->index;
	i = 1;
	while (parser != lis_start)
	{
		if (benchmark < parser->index)
		{
			benchmark = parser->index;
			i++;
		}
		parser = parser->next;
	}
	return (i);
}

/* This function checks whether or not *node is part of the *lis_start lis */
int part_of_lis(struct s_node *lis_start, struct s_node *node)
{
	struct s_node *parser;
	int benchmark;

	if (lis_start == NULL)
		return (0);
	else if (lis_start == node)
		return (1);
	parser = lis_start->next;
	benchmark = lis_start->index;
	while (parser != node)
	{
		if (benchmark <= parser->index)
		{
			benchmark = parser->index;
		}
		parser = parser->next;
	}
	if (benchmark <= node->index)
		return (1);
	else
		return (0);
}
