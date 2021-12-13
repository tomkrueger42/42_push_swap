/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/14 00:53:22 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function finds the right position for *node in *head */
int	find_right_position(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;
	int				size;

	i = 0;
	if (c == 'a')
	{
		parser = head->a;
		size = lst_size(head->a);
	}
	else if (c == 'b')
	{
		parser = head->b;
		size = lst_size(head->b);
	}
	while (c == 'a' && (parser != node || i == 0))
	{
		if (size <= 1 || (parser->prev->index < node->index && node->index < parser->index) || ((parser->prev->index < node->index || node->index < parser->index) && lis_break(c, parser)))
			return (i);
		parser = parser->next;
		i++;
	}
	while (c == 'b' && (parser != node || i == 0))
	{
		if (size <= 1 || (parser->prev->index > node->index && node->index > parser->index) || ((parser->prev->index > node->index || node->index > parser->index) && lis_break(c, parser)))
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
