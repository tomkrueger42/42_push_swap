/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/22 11:18:34 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_sorted(char c, struct s_head *head)
{
	int	i;

	if (c == 'b')
	{
		i = find_right_slot(c, head->a, head);
		while (i < 0 && i++)
		{
			rotate(c, head);
			printf("rotate\n");
		}
		while (i > 0 && i--)
		{
			revrotate(c, head);
			printf("revrotate\n");
		}
		push(c, head);
		/* find new longest possible snake after each push('b')!! for greater efficiency!! */
		// the following two lines are needed 'cause find_right_slot() still has its difficulties with 2 nodes on one stack
		if (lst_size(head->b) == 2 && head->b->content->value < head->b->next->content->value)
			swap(c, head);
	}
	print_go_brrrrr(head);
}

/* int	find_right_slot(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	if (lst_size(head->b) <= 1 || (c == 'b' && ((node->content->value > head->b->content->value && snake_break(c, head->b)) || (node->content->value < head->b->prev->content->value && snake_break(c, head->b)))))
		return (0);
	if (c == 'b')
	{
		parser = head->b;
		while (parser != node || i == 0)
		{
			if (lst_size(head->b) <= 1 || (node->content->value < parser->content->value &&
				(node->content->value > parser->next->content->value
				|| snake_break(c, parser))))
				return ((i < lst_size(head->b) / 2 ? i : -(lst_size(head->b) - i)));
			parser = parser->next;
			i++;
		}
	}
	return (-1);
} */


int	find_right_slot(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 1;
	if (first_slot(c, node, head))
		return (0);
	if (c == 'b')
		parser = head->b;
	while (c == 'b' && (parser != node || i == 1))
	{
		if (node->content->value < parser->content->value &&
			(node->content->value > parser->next->content->value
			|| snake_break(c, parser)))
			return ((i < lst_size(head->b) / 2 ? i : -(lst_size(head->b) - i)));
		parser = parser->next;
		i++;
	}
	return (-1);
}

/* This function returns either 0 or 1 wether or not *node can be pushed into the first slot of *head */
int	first_slot(char c, struct s_node *node, struct s_head *head)
{
	if (lst_size(head->b) <= 1 || (c == 'b' && ((node->content->value > head->b->content->value && snake_break(c, head->b)) || (node->content->value < head->b->prev->content->value && snake_break(c, head->b)))))
		return (1);
	return (0);
}

/* This function returns either 0 or 1 wether or not s_node *node the start of a snake is */
int	snake_break(char c, struct s_node *node)
{
	if (c == 'a' && node->content->value < node->prev->content->value)
		return (1);
	else if (c == 'b' && node->content->value > node->prev->content->value)
		return (1);
	return (0);
}
