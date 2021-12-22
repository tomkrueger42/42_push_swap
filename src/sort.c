/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/22 01:04:50 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() finds the longest increasing sub-sequence in stack a and isolates
that with push_sorted() */
void	lis(t_head *head)
{
	t_node	*parser;
	t_node	*lis_start;
	int		lis_len;
	int		i;

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
		if (lis_len == lst_size(parser))
			break ;
		efficient_rotation(lis_start, head->a, head->b, head);
		push('b', true, head);
	}
}

/* This f() returns the length of an increasing subsequence */
int	increasing_subsequence(t_node *lis_start)
{
	t_node	*parser;
	int		benchmark;
	int		i;

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

/* This f() checks whether or not *node is part of the *lis_start lis */
int	part_of_lis(t_node *lis_start, t_node *node)
{
	t_node	*parser;
	int		benchmark;

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

/* This f() finds the right position for *node in stack *dst */
int	find_right_position(t_node *node, t_node *dst)
{
	int	i;

	i = 0;
	if (lst_size(dst) <= 1)
		return (0);
	while (true)
	{
		if ((dst->prev->index <= node->index && node->index <= dst->index)
			|| ((dst->prev->index <= node->index || node->index <= dst->index)
				&& dst->index <= dst->prev->index))
			return (i);
		dst = dst->next;
		i++;
	}
	return (0);
}

/* This f() merges both stacks onto stack a sorted */
void	merge_to_stack_a(t_head *head)
{
	t_node	*parser;
	int		i;

	while (head->b != NULL)
	{
		efficient_rotation(NULL, head->b, head->a, head);
		push('a', true, head);
	}
	i = 0;
	parser = head->a;
	while (parser->prev->index < parser->index)
	{
		parser = parser->next;
		i++;
	}
	if (i > lst_size(head->a) / 2)
		i = -lst_size(head->a) + i;
	while (i > 0 && i--)
		rotate('a', true, head);
	while (i < 0 && i++)
		revrotate('a', true, head);
}
