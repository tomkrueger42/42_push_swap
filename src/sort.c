/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/02 00:23:26 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_sorted(char c, struct s_head *head)
{
	int	count;

	if (c == 'a')
	{
		count = find_right_position(c, head->b, head);
		count = count <= lst_size(head->a) / 2 ? count : -(lst_size(head->a) - count);
		while (count > 0 && count--)
		{
			rotate(c, head);
		}
		while (count < 0 && count++)
		{
			revrotate(c, head);
		}
		push(c, head);
	}
	else if (c == 'b')
	{
		count = find_right_position(c, head->a, head);
		count = count <= lst_size(head->b) / 2 ? count : -(lst_size(head->b) - count);
		while (count > 0 && count--)
			rotate(c, head);
		while (count < 0 && count++)
			revrotate(c, head);
		push(c, head);
	}
}

/* This function finds the right position for *node in *head */
int	find_right_position(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	if (c == 'a')
		parser = head->a;
	else if (c == 'b')
		parser = head->b;
	while (c == 'a' && (parser != node || i == 0))
	{
		if (lst_size(head->a) <= 1 || (parser->prev->index < node->index && node->index < parser->index) || ((parser->prev->index < node->index || node->index < parser->index) && lis_break(c, parser)))
			return (i);
		parser = parser->next;
		i++;
	}
	while (c == 'b' && (parser != node || i == 0))
	{
		if (lst_size(head->b) <= 1 || (parser->prev->index > node->index && node->index > parser->index) || ((parser->prev->index > node->index || node->index > parser->index) && lis_break(c, parser)))
			return (i);
		parser = parser->next;
		i++;
	}
	return (0);
}

/* This function returns either 0 or 1 wether or not s_node *node the start of 
a snake is */
int	lis_break(char c, struct s_node *node)
{
	if (c == 'a' && node->index < node->prev->index)
		return (1);
	if (c == 'b' && node->index > node->prev->index)
		return (1);
	return (0);
}
