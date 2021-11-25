/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/11/25 16:56:12 by tkruger          ###   ########.fr       */
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
		if (snake_len < find_snake(parser))
		{
			snake_len = find_snake(parser);
			snake_start = i;
		}
		parser = parser->next;
		i++;
	}

	if (snake_len == lst_size(head->a))
		return ;

// some weird rotations in the beginning cause it is trying to find the lis beginning and then rotates to first non-ordered element
	if (snake_start <= lst_size(head->a) / 2)
	{
		while (snake_start > 0)
		{
			rotate('a', head);
			snake_start--;
		}
	}
	else
	{
		while (snake_start < lst_size(head->a))
		{
			revrotate('a', head);
			snake_start++;
		}
		snake_start = 0;
	}
	parser = head->a;
	benchmark = head->a->content;
	rotate('a', head);
	while (parser != head->a)
	{
		if (benchmark->value > head->a->content->value)
		{
			push_sorted('b', head);
		}
		else
		{
			benchmark = head->a->content;
			rotate('a', head);
		}
	}
	//print_go_brrrrr(head);
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

int	part_of_lis(struct s_node *lis_start, struct s_node *node)
{
	struct s_node	*parser;
	struct s_content	*benchmark;

	parser = lis_start->next;
	benchmark = lis_start->content->value;
	while (parser != node)
	{
		if (benchmark->value < parser->content->value)
		{
			benchmark = parser->content;
		}
		parser = parser->next;
	}
	if (benchmark->value <=)
}

int	value_at(struct s_node *node, int pos)
{
	while (pos-- > 0)
	{
		node = node->next;
	}
	return (node->content->value);
}
