/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:20:53 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 17:41:04 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() prints out stacks a & b and the instruction stack to stdout */
void	print_go_brrrrr(t_head *head)
{
	t_node	*a_parser;
	t_node	*b_parser;

	a_parser = head->a != NULL ? head->a->next : NULL;
	b_parser = head->b != NULL ? head->b->next : NULL;
	printf("stack a: | stack b:\n");
	if (head->a && head->b)
		printf("%i\t | %i\n", head->a->index, head->b->index);
	else if (head->a)
		printf("%i\n", head->a->index);
	else if (head->b)
		printf("\t | %i\n", head->b->index);
	while (a_parser != head->a && b_parser != head->b && a_parser != NULL && b_parser != NULL)
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

/* This f() prints out the rotations stored in t_rotation *r */
void	print_r(t_rotation *r, t_rotation *ben, bool print_ben)
{
	printf("r_s: %i\n", r->r_s);
	printf("rr_s: %i\n", r->rr_s);
	printf("r_d: %i\n", r->r_d);
	printf("rr_d: %i\n", r->rr_d);
	printf("x_s: %i\n", r->x_s);
	printf("x_d: %i\n", r->x_d);
	if (print_ben == false)
		return ;
	printf("benchmark r_s: %i\n", ben->r_s);
	printf("benchmark rr_s: %i\n", ben->rr_s);
	printf("benchmark r_d: %i\n", ben->r_d);
	printf("benchmark rr_d: %i\n", ben->rr_d);
	printf("benchmark x_s: %i\n", ben->x_s);
	printf("benchmark x_d: %i\n", ben->x_d);
}
