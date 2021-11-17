/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/11/17 14:34:49 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void best_snake(struct s_head *head)
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

	printf("snake_start:\t%i\n", snake_start);
	printf("snake_len:\t%i\n", snake_len);
	if (snake_start + snake_len > lst_size(head->a))
	{
		while (snake_start + snake_len > lst_size(head->a) && snake_start--)
			rotate('a', head);
		while (snake_start > 0 && snake_start--)
			push('b', head);
	}
	if (snake_start + snake_len < lst_size(head->a))
	{
		while (snake_start + snake_len < lst_size(head->a) && snake_start++)
			revrotate('a', head);
		while (snake_start > 0 && snake_start--)
			push('b', head);
	}
	printf("snake_start:\t%i\n", snake_start);
	printf("snake_len:\t%i\n", snake_len);
}

int find_snake(struct s_node *start)
{
	struct s_node *parser;
	int i;

	parser = start;
	i = 1;
	printf("start->content->value: %i\n", start->content->value);
	while (parser->content->value < parser->next->content->value ||
		parser->content->value < start->content->value)
	{
		i++;
		parser = parser->next;
	}
	return (i);
}
