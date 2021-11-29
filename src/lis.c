/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/11/26 13:54:29 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function finds the longest increasing sub-sequence in stack a and isolates that with push_sorted() */
int lis(struct s_head *head)
{
	struct s_node		*parser;
	struct s_node		*lis_start;
	int					lis_len;
	int					i;

	parser = head->a;
	lis_len = 0;
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
	i = 0;
	parser = head->a;
	while ((head->a != parser || i++ == 0) && lst_size(head->a) > lis_len)
	{
		if (part_of_lis(lis_start, head->a))
			rotate('a', head);
		else
			push_sorted('b', head);
			lis_len = lis(head);
	}
	return (lis_len);
}

/* This function returns the length of an increasing subsequence */
int increasing_subsequence(struct s_node *lis_start)
{
	struct s_node		*parser;
	struct s_content	*benchmark;
	int					i;

	parser = lis_start;
	benchmark = lis_start->content;
	i = 0;
	while (parser != lis_start || i++ == 0)
	{
		if (benchmark->value < parser->content->value)
		{
			benchmark = parser->content;
			i++;
		}
		parser = parser->next;
	}
	return (--i);
}

/* This function checks whether or not *node is part of the *lis_start lis */
int	part_of_lis(struct s_node *lis_start, struct s_node *node)
{
	struct s_node		*parser;
	struct s_content	*benchmark;

	parser = lis_start->next;
	benchmark = lis_start->content;
	if (lis_start == node)
		return (1);
	while (parser != node)
	{
		if (benchmark->value <= parser->content->value)
		{
			benchmark = parser->content;
		}
		parser = parser->next;
	}
	if (benchmark->value <= node->content->value)
		return (1);
	else
		return (0);
}

/* This function returns the value of the content element *node */
int	value_at(struct s_node *node, int pos)
{
	while (pos-- > 0)
	{
		node = node->next;
	}
	return (node->content->value);
}
