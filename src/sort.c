/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/17 22:29:33 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_sorted(char c, struct s_head *head)
{
	int	i;

	if (c == 'a')
	{
		i = find_right_slot('a', head->b, head);
		while (i-- > 0)
			rotate('a', head);
		push('a', head);
		if (lst_size(head->a) == 2 && head->a < head->a->next)
			swap('a', head);
	}
	else if (c == 'b')
	{
		printf("in push_sorted, b\n");
		i = find_right_slot('b', head->a, head);
		while (i-- > 0)
			rotate('b', head);
		push('b', head);
		if (lst_size(head->b) == 2 && head->b->content->value < head->b->next->content->value)
			swap('b', head);
	}
}

int	find_right_slot(char c, struct s_node *node, struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	if ((c == 'a' && (node->content->value > node->prev->content->value || head->a == NULL)) ||
		(c == 'b' && (node->content->value < node->prev->content->value || head->b == NULL)))
		return (i);
	if (c == 'a')
	{
		parser = head->a;
		while (parser != node || i == 0)
		{
			if ((node->content->value > parser->content->value &&
				node->content->value < parser->next->content->value) || lst_size(head->a) == 1)
				return (i);
			parser = parser->next;
			i++;
		}
	}
	else if (c == 'b')
	{
		parser = head->b;
		while (parser != node || i == 0)
		{
			if ((node->content->value < parser->content->value &&
				node->content->value > parser->next->content->value) || lst_size(head->b) == 1)
				return (i);
			parser = parser->next;
			i++;
		}
	}
	return (-1);
}
