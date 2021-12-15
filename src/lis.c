/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:05:40 by tomkrueger        #+#    #+#             */
/*   Updated: 2021/12/15 17:01:26 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function finds the longest increasing sub-sequence in stack a and isolates that with push_sorted() */
void lis(struct s_head *head)
{
	struct s_node *parser;
	struct s_node *lis_start;
	int lis_len;
	int i;

	lis_len = 0;
	while (lst_size(head->a) > lis_len)
	{
		parser = head->a;
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
		//make_this_efficient(lis_start, head);
		//print_go_brrrrr(head);
		efficient_rotation(lis_start, head->a, head->b, head);
		push('b', head);
	}
}

void efficient_rotation(struct s_node *lis_start, struct s_node *src, struct s_node *dst, struct s_head *head)
{
	struct s_rotation *rollercoaster;

	rollercoaster = ft_calloc(1, sizeof(struct s_rotation));
	if (rollercoaster == NULL)
		free_exit("Error\n", EXIT_FAILURE, head);
	rollercoaster->best_delta = INT32_MAX;
	rollercoaster->best_rev_delta = INT32_MAX;
	//printf("lis_start: %i, src: %i\n", lis_start->index, src->index);
	while (rollercoaster->rotate_src < lst_size(src))
	{
		//printf("rotate_src: %i\n", rollercoaster->rotate_src);
		if (part_of_lis(lis_start, src) == 0)
		{
			set_rotations(rollercoaster, src, dst);
			benchmark_rotations(rollercoaster);
		}
		rollercoaster->rotate_src++;
		src = src->next;
	}
	rock_n_roll(rollercoaster, dst, head);
	free(rollercoaster);
}

void	set_rotations(struct s_rotation *rollercoaster, struct s_node *src, struct s_node *dst)
{
	rollercoaster->rev_rotate_src = rollercoaster->rotate_src == 0 ? 0 : lst_size(src) - rollercoaster->rotate_src;
	rollercoaster->rotate_dst = find_right_position(src, dst);
	rollercoaster->rev_rotate_dst = rollercoaster->rotate_dst == 0 ? 0 : lst_size(dst) - rollercoaster->rotate_dst;
	rollercoaster->rotate_all = rollercoaster->rotate_src < rollercoaster->rotate_dst ? rollercoaster->rotate_src : rollercoaster->rotate_dst;
	rollercoaster->rev_rotate_all = rollercoaster->rev_rotate_src < rollercoaster->rev_rotate_dst ? rollercoaster->rev_rotate_src : rollercoaster->rev_rotate_dst;
	rollercoaster->delta = rollercoaster->rotate_src < rollercoaster->rotate_dst ? rollercoaster->rotate_dst - rollercoaster->rotate_src : rollercoaster->rotate_src - rollercoaster->rotate_dst;
	rollercoaster->rev_delta = rollercoaster->rev_rotate_src < rollercoaster->rev_rotate_dst ? rollercoaster->rev_rotate_dst - rollercoaster->rev_rotate_src : rollercoaster->rev_rotate_src - rollercoaster->rev_rotate_dst;
}

void benchmark_rotations(struct s_rotation *rollercoaster)
{
	/* printf("faulty src: %i\n", rollercoaster->rotate_src);
	printf("faulty dst: %i\n", rollercoaster->rotate_dst);
	printf("faulty all: %i\n", rollercoaster->rotate_all);
	printf("faulty del: %i\n", rollercoaster->delta);
	printf("rfaulty src: %i\n", rollercoaster->rev_rotate_src);
	printf("rfaulty dst: %i\n", rollercoaster->rev_rotate_dst);
	printf("rfaulty all: %i\n", rollercoaster->rev_rotate_all);
	printf("rfaulty del: %i\n", rollercoaster->rev_delta); */
	if (rollercoaster->rotate_all + rollercoaster->delta <= rollercoaster->rev_rotate_all + rollercoaster->rev_delta && rollercoaster->rotate_all + rollercoaster->delta < rollercoaster->best_rotate_all + rollercoaster->best_delta)
	{
		//printf("AHHHHHHHHH\n");
		rollercoaster->best_rotate_src = rollercoaster->rotate_src;
		rollercoaster->best_rotate_dst = rollercoaster->rotate_dst;
		rollercoaster->best_rotate_all = rollercoaster->rotate_all;
		rollercoaster->best_delta = rollercoaster->delta;
	}
	if (rollercoaster->rotate_all + rollercoaster->delta > rollercoaster->rev_rotate_all + rollercoaster->rev_delta && rollercoaster->rev_rotate_all + rollercoaster->rev_delta < rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta)
	{
		//printf("NOOOOOOOOOO\n");
		rollercoaster->best_rev_rotate_src = rollercoaster->rev_rotate_src;
		rollercoaster->best_rev_rotate_dst = rollercoaster->rev_rotate_dst;
		rollercoaster->best_rev_rotate_all = rollercoaster->rev_rotate_all;
		rollercoaster->best_rev_delta = rollercoaster->rev_delta;
	}
}

void rock_n_roll(struct s_rotation *rollercoaster, struct s_node *dst, struct s_head *head)
{
	char s;
	char d;

	/* printf("r src: %i\n", rollercoaster->best_rotate_src);
	printf("r dst: %i\n", rollercoaster->best_rotate_dst);
	printf("r all: %i\n", rollercoaster->best_rotate_all);
	printf("r del: %i\n", rollercoaster->best_delta);
	printf("rr src: %i\n", rollercoaster->best_rev_rotate_src);
	printf("rr dst: %i\n", rollercoaster->best_rev_rotate_dst);
	printf("rr all: %i\n", rollercoaster->best_rev_rotate_all);
	printf("rr del: %i\n", rollercoaster->best_rev_delta); */
	if (dst == head->a)
	{
		s = 'b';
		d = 'a';
	}
	else
	{
		s = 'a';
		d = 'b';
	}
	if (rollercoaster->best_rotate_all + rollercoaster->best_delta <= rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta)
	{
		while (rollercoaster->best_rotate_all-- > 0)
		{
			rotate('r', head);
			//sleep(1);
			//printf("a\n");
		}
		while (rollercoaster->best_rotate_src > rollercoaster->best_rotate_dst && rollercoaster->best_delta-- > 0)
		{
			rotate(s, head);
			//sleep(1);
			//printf("b\n");
		}
		while (rollercoaster->best_rotate_dst > rollercoaster->best_rotate_src && rollercoaster->best_delta-- > 0)
		{
			rotate(d, head);
			//sleep(1);
			//printf("c\n");
		}
	}
	else/*  if (rollercoaster->best_rotate_all + rollercoaster->best_delta > rollercoaster->best_rev_rotate_all + rollercoaster->best_rev_delta) */
	{
		while (rollercoaster->best_rev_rotate_all-- > 0)
		{
			revrotate('r', head);
			//sleep(1);
			//printf("d\n");
		}
		while (rollercoaster->best_rev_rotate_src > rollercoaster->best_rev_rotate_dst && rollercoaster->best_rev_delta-- > 0)
		{
			revrotate(s, head);
			//sleep(1);
			//printf("e\n");
		}
		while (rollercoaster->best_rev_rotate_dst > rollercoaster->best_rev_rotate_src && rollercoaster->best_rev_delta-- > 0)
		{
			revrotate(d, head);
			//sleep(1);
			//printf("f\n");
		}
	}
}

void make_this_efficient(struct s_node *lis_start, struct s_head *head)
{
	struct s_node *parser;
	int rotate_a;
	int rev_rotate_a;
	int rotate_b;
	int rev_rotate_b;
	int rotate_r;
	int rev_rotate_r;
	int delta;
	int rev_delta;
	int best_rotate_a;
	int best_rev_rotate_a;
	int best_rotate_b;
	int best_rev_rotate_b;
	int best_rotate_r;
	int best_rev_rotate_r;
	int best_delta;
	int best_rev_delta;

	parser = head->a;
	rotate_a = 0;
	best_rotate_a = 0;
	best_rev_rotate_a = 0;
	best_rotate_b = 0;
	best_rev_rotate_b = 0;
	best_rotate_r = 0;
	best_rev_rotate_r = 0;
	best_delta = INT32_MAX;
	best_rev_delta = INT32_MAX;
	while (parser != head->a || rotate_a == 0)
	{
		if (part_of_lis(lis_start, parser) == 0)
		{
			rev_rotate_a = rotate_a == 0 ? 0 : lst_size(head->a) - rotate_a;
			rotate_b = find_right_position(parser, head->b);
			rev_rotate_b = rotate_b == 0 ? 0 : lst_size(head->b) - rotate_b;
			rotate_r = rotate_a < rotate_b ? rotate_a : rotate_b;
			rev_rotate_r = rev_rotate_a < rev_rotate_b ? rev_rotate_a : rev_rotate_b;
			delta = rotate_a < rotate_b ? rotate_b - rotate_a : rotate_a - rotate_b;
			rev_delta = rev_rotate_a < rev_rotate_b ? rev_rotate_b - rev_rotate_a : rev_rotate_a - rev_rotate_b;
			if (rotate_r + delta <= rev_rotate_r + rev_delta && rotate_r + delta < best_rotate_r + best_delta)
			{
				best_rotate_a = rotate_a;
				best_rotate_b = rotate_b;
				best_rotate_r = rotate_r;
				best_delta = delta;
			}
			if (rotate_r + delta > rev_rotate_r + rev_delta && rev_rotate_r + rev_delta < best_rev_rotate_r + best_rev_delta)
			{
				best_rev_rotate_a = rev_rotate_a;
				best_rev_rotate_b = rev_rotate_b;
				best_rev_rotate_r = rev_rotate_r;
				best_rev_delta = rev_delta;
			}
		}
		rotate_a++;
		parser = parser->next;
	}
	if (best_rotate_r + best_delta <= best_rev_rotate_r + best_rev_delta)
	{
		while (best_rotate_r-- > 0)
			rotate('r', head);
		while (best_rotate_a > best_rotate_b && best_delta-- > 0)
			rotate('a', head);
		while (best_rotate_b > best_rotate_a && best_delta-- > 0)
			rotate('b', head);
	}
	else if (best_rotate_r + best_delta > best_rev_rotate_r + best_rev_delta)
	{
		while (best_rev_rotate_r-- > 0)
			revrotate('r', head);
		while (best_rev_rotate_a > best_rev_rotate_b && best_rev_delta-- > 0)
			revrotate('a', head);
		while (best_rev_rotate_b > best_rev_rotate_a && best_rev_delta-- > 0)
			revrotate('b', head);
	}
	push('b', head);
}

/* This function returns the length of an increasing subsequence */
int increasing_subsequence(struct s_node *lis_start)
{
	struct s_node *parser;
	int benchmark;
	int i;

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
int part_of_lis(struct s_node *lis_start, struct s_node *node)
{
	struct s_node *parser;
	int benchmark;

	if (lis_start == NULL)
		return (0);
	else if (lis_start == node)
		return (1);
	parser = lis_start->next;
	benchmark = lis_start->index;
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
