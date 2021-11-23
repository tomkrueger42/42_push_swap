/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/23 18:38:50 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_sorted(char c, struct s_head *head)
{
	int	i;

	if (c == 'a')
	{
		i = find_right_slot(c, head->b, head);
		while (i > 0 && i--)
		{
			rotate(c, head);
		}
		while (i < 0 && i++)
		{
			revrotate(c, head);
		}
		push(c, head);
	}
	if (c == 'b')
	{
		i = find_right_slot(c, head->a, head);
		while (i > 0 && i--)
			rotate(c, head);
		while (i < 0 && i++)
			revrotate(c, head);
		push(c, head);
		/* find new longest possible snake after each push('b')!! for greater efficiency!! */
	}
}

/* This function finds the right slot for *node in *head */
int	find_right_slot(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	if (first_slot(c, node, head))
	{
		//i = 0;
		return (0);
	}
	if (c == 'a')
		parser = head->a;
	else if (c == 'b')
		parser = head->b;
	while (c == 'a' && (parser != node || i == 0))
	{
		if ((node->content->value > parser->prev->content->value && (node->content->value < parser->content->value)) || (node->content->value < parser->content->value && snake_break(c, parser)) || (node->content->value > parser->prev->content->value && snake_break(c, parser)))
			return (i <= lst_size(head->a) / 2 ? i : -(lst_size(head->a) - i));
		parser = parser->next;
		i++;
	}
	while (c == 'b' && (parser != node || i == 0))
	{
		if ((node->content->value < parser->prev->content->value && (node->content->value > parser->content->value)) || (node->content->value > parser->content->value && snake_break(c, parser)) || (node->content->value < parser->prev->content->value && snake_break(c, parser)))
			return (i <= lst_size(head->b) / 2 ? i : -(lst_size(head->b) - i));
		parser = parser->next;
		i++;
	}
	return (0);
}

/* This function returns either 0 or 1 wether or not *node can be pushed into 
the first slot of *head */
int	first_slot(char c, struct s_node *node, struct s_head *head)
{
	if (c == 'a' && (lst_size(head->a) <= 1 || ((node->content->value < head->a->content->value && snake_break(c, head->a))/*  || (node->content->value > head->a->prev->content->value && snake_break(c, head->a)) */)))
		return (1);
	else if (c == 'b' && (lst_size(head->b) <= 1 || ((node->content->value > head->b->content->value && snake_break(c, head->b)) || (node->content->value < head->b->prev->content->value && snake_break(c, head->b)))))
		return (1);
	return (0);
}

/* This function returns either 0 or 1 wether or not s_node *node the start of 
a snake is */
int	snake_break(char c, struct s_node *node)
{
	if (c == 'a' && node->content->value < node->prev->content->value)
		return (1);
	if (c == 'b' && node->content->value > node->prev->content->value)
		return (1);
	return (0);
}
