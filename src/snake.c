/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/11/17 22:20:28 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_snake(struct s_node *start)
{
	struct s_node	*parser;
	int				i;

	parser = start;
	i = 1;
	while (parser->content->value < parser->next->content->value)
	{
		i++;
		parser = parser->next;
	}
	if (parser->next->content->value < start->content->value)
	{
		i++;
		parser = parser->next;
	}
	while (parser->content->value < parser->next->content->value &&
		parser->next->content->value < start->content->value)
	{
		i++;
		parser = parser->next;
	}
	return (i);
}

/* This function saves the attributes of the longest snake */
void big_snake_ahhh(struct s_head *head)
{
	struct s_node *parser;
	int snake_len;
	int snake_start;
	int i;

	parser = head->a;
	snake_len = 0;
	i = 0;
	while (parser != head->a || i == 0)
	{
		if (snake_len < find_snake(parser))
		{
			snake_len = find_snake(parser);
			snake_start = i;
		}
		parser = parser->next;
		i++;
	}
	snake_in_isolation(snake_start, snake_len, head);
}

void	snake_in_isolation(int snake_start, int snake_len, struct s_head *head)
{
	if (snake_start + snake_len > lst_size(head->a))
	{
		while (snake_start + snake_len > lst_size(head->a) && snake_start-- >= 0)
			rotate('a', head);
		while (snake_start > 0 && snake_start-- >= 0)
			push_sorted('b', head);
	}
	if (snake_start + snake_len < lst_size(head->a))
	{
		while (snake_start + snake_len < lst_size(head->a) && snake_start++ >= 0)
			revrotate('a', head);
		while (snake_start > 0 && snake_start-- >= 0)
			push_sorted('b', head);
	}
}
