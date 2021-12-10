/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/10 19:51:57 by tkruger          ###   ########.fr       */
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

	lis_len = 0;
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
	while (lst_size(head->a) > lis_len)
		make_this_efficient(lis_start, head);
	return (lis_len);
}
	
void	make_this_efficient(struct s_node *lis_start, struct s_head *head)
{
	struct s_node	*parser;
	int				rotate_a;
	int				rev_rotate_a;
	int				rotate_b;
	int				rev_rotate_b;
	int				rotate_r;
	int				rev_rotate_r;
	int				delta;
	int				rev_delta;
	int				B_rotate_a;
	int				B_rev_rotate_a;
	int				B_rotate_b;
	int				B_rev_rotate_b;
	int				B_rotate_r;
	int				B_rev_rotate_r;
	int				B_delta;
	int				B_rev_delta;

	parser = head->a;
	rotate_a = 0;
	B_rotate_a = 0;
	B_rev_rotate_a = 0;
	B_rotate_b = 0;
	B_rev_rotate_b = 0;
	B_rotate_r = 0;
	B_rev_rotate_r = 0;
	B_delta = INT32_MAX;
	B_rev_delta = INT32_MAX;
	while (parser != head->a || rotate_a == 0)
	{
		if (part_of_lis(lis_start, parser) == 0)
		{
			rev_rotate_a = rotate_a == 0 ? 0 : lst_size(head->a) - rotate_a;
			rotate_b = find_right_position('b', parser, head);
			rev_rotate_b = rotate_b == 0 ? 0 : lst_size(head->b) - rotate_b;
			rotate_r = rotate_a < rotate_b ? rotate_a : rotate_b;
			rev_rotate_r = rev_rotate_a < rev_rotate_b ? rev_rotate_a : rev_rotate_b;
			delta = rotate_a < rotate_b ? rotate_b - rotate_a : rotate_a - rotate_b;
			rev_delta = rev_rotate_a < rev_rotate_b ? rev_rotate_b - rev_rotate_a : rev_rotate_a - rev_rotate_b;
			if (rotate_r + delta <= rev_rotate_r + rev_delta && rotate_r + delta < B_rotate_r + B_delta)
			{
				B_rotate_a = rotate_a;
				B_rotate_b = rotate_b;
				B_rotate_r = rotate_r;
				B_delta = delta;
			}
			if (rotate_r + delta > rev_rotate_r + rev_delta && rev_rotate_r + rev_delta < B_rev_rotate_r + B_rev_delta)
			{
				B_rev_rotate_a = rev_rotate_a;
				B_rev_rotate_b = rev_rotate_b;
				B_rev_rotate_r = rev_rotate_r;
				B_rev_delta = rev_delta;
			}
		}
		rotate_a++;
		parser = parser->next;
	}
	if (B_rotate_r + B_delta <= B_rev_rotate_r + B_rev_delta)
	{
		while (B_rotate_r-- > 0)
			rotate('r', head);
		while (B_rotate_a > B_rotate_b && B_delta-- > 0)
			rotate('a', head);
		while (B_rotate_b > B_rotate_a && B_delta-- > 0)
			rotate('b', head);
	}
	else if (B_rotate_r + B_delta > B_rev_rotate_r + B_rev_delta)
	{
		while (B_rev_rotate_r-- > 0)
			revrotate('r', head);
		while (B_rev_rotate_a > B_rev_rotate_b && B_rev_delta-- > 0)
			revrotate('a', head);
		while (B_rev_rotate_b > B_rev_rotate_a && B_rev_delta-- > 0)
			revrotate('b', head);
	}
	push('b', head);
}

/* This function returns the length of an increasing subsequence */
int increasing_subsequence(struct s_node *lis_start)
{
	struct s_node		*parser;
	int					benchmark;
	int					i;

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
int	part_of_lis(struct s_node *lis_start, struct s_node *node)
{
	struct s_node		*parser;
	int					benchmark;

	parser = lis_start->next;
	benchmark = lis_start->index;
	if (lis_start == node)
		return (1);
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
