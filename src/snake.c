/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/11/24 19:29:56 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function returns the length of a snake */
int find_snake(struct s_node *start)
{
	struct s_node		*parser;
	struct s_content	*benchmark;
	int					i;

	parser = start;
	benchmark = start->content;
	//printf("start value: %i\n", start->content->value);
	i = 0;
	while (parser != start || i++ == 0)
	{
		if (benchmark->value < parser->content->value)
		{
			//printf("in snake: %i\n", parser->content->value);
			benchmark = parser->content;
			i++;
		}
		parser = parser->next;
	}
	/* while (parser->content->value < parser->next->content->value)
	{
		parser = parser->next;
		i++;
	}
	if (parser->next->content->value < start->content->value)
	{
		parser = parser->next;
		i++;
	}
	while (parser->content->value < parser->next->content->value &&
		parser->next->content->value < start->content->value)
	{
		parser = parser->next;
		i++;
	} */
	return (--i);
}

/* This function finds the longest snake and calls snake_in_isolation() */
void big_snake_ahhh(struct s_head *head)
{
	struct s_node		*parser;
	struct s_content	*benchmark;
	int					snake_len;
	int					snake_start;
	int					i;

	parser = head->a;
	snake_len = 0;
	i = 0;
	while (parser != head->a || i == 0)
	{
		//printf("c\n");
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

	if (snake_start <= lst_size(head->a) / 2)
	{
		while (snake_start > 0)
		{
			printf("a\n");
			rotate('a', head);
			snake_start--;
		}
	}
	else
	{
		while (snake_start < lst_size(head->a))
		{
			printf("b\n");
			revrotate('a', head);
			snake_start++;
		}
		snake_start = 0;
	}
	parser = head->a->next;
	benchmark = head->a->content;
	while (parser != head->a)
	{
		rotate('a', head);
		if (benchmark->value > parser->content->value)
		{
			push_sorted('b', head);
		}
		benchmark = parser->content;
		parser = parser->next;
	}
	print_go_brrrrr(head);
	//snake_in_isolation(snake_start, snake_len, head);
}

/* This function isolates a snake on stack->a */
void	snake_in_isolation(int snake_start, int snake_len, struct s_head *head)
{
	if (snake_start + snake_len <= lst_size(head->a))
	{
		while (snake_start + snake_len < lst_size(head->a) && snake_start++ >= 0)
			rotate('a', head);
		while (snake_start > 0 && snake_start-- >= 0)
			push_sorted('b', head);
	}
	if (snake_start + snake_len > lst_size(head->a))
	{
		while (snake_start + snake_len > lst_size(head->a) && snake_start-- >= 0)
			revrotate('a', head);
		while (snake_start > 0 && snake_start-- >= 0)
			push_sorted('b', head);
	}
}
