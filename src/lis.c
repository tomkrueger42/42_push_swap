/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/21 17:21:34 by tkruger          ###   ########.fr       */
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
