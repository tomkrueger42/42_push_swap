/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:20:53 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/22 14:05:49 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* This f() prints out stacks a & b and the instruction stack to stdout */
void	print_go_brrrrr(t_head *head)
{
	t_node	*a_parser;
	t_node	*b_parser;

	if (head->a != NULL)
		a_parser = head->a->next;
	else
		a_parser = NULL;
	if (head->b != NULL)
		b_parser = head->b->next;
	else
		b_parser = NULL;
	printf("stack a: | stack b:\n");
	if (head->a && head->b)
		printf("%i\t | %i\n", head->a->index, head->b->index);
	else if (head->a)
		printf("%i\n", head->a->index);
	else if (head->b)
		printf("\t | %i\n", head->b->index);
	while (a_parser != head->a && b_parser != head->b && a_parser != NULL
		&& b_parser != NULL)
	{
		printf("%i \t | %i\n", a_parser->index, b_parser->index);
		a_parser = a_parser->next;
		b_parser = b_parser->next;
	}
	while (a_parser != head->a && a_parser != NULL)
	{
		printf("%i\n", a_parser->index);
		a_parser = a_parser->next;
	}
	while (b_parser != head->b && b_parser != NULL)
	{
		printf("\t | %i\n", b_parser->index);
		b_parser = b_parser->next;
	}
	printf("\n------------------------------\n");
}

/* This f() prints out the rotations stored in t_rotation *rotations */
void	print_rotations(t_rotation *rotations)
{
	printf("pos: %i\n", rotations->pos);
	printf("src: %i\n", rotations->src);
	printf("dst: %i\n", rotations->dst);
	printf("x: %i\n", rotations->x);
}
