/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:15 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/03 16:25:45 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') && head->a != head->a->next /* && head->a != NULL */)
	{
		head->a->prev->next = head->a->next;
		head->a->next->prev = head->a->prev;
		head->a->next->next->prev = head->a;
		head->a->next = head->a->next->next;
		head->a->prev = head->a->prev->next;
		head->a->prev->next = head->a;
		if (c == 'a')
			head->i = insert_node_b4(head->i, SA);
	}
	else if ((c == 'b' || c == 'B') && head->b != head->b->next /* && head->b != NULL */)
	{
		head->b->prev->next = head->b->next;
		head->b->next->prev = head->b->prev;
		head->b->next->next->prev = head->b;
		head->b->next = head->b->next->next;
		head->b->prev = head->b->prev->next;
		head->b->prev->next = head->b;
		if (c == 'b')
			head->i = insert_node_b4(head->i, SB);
	}
	else if (c == 'c' /* && head->a != NULL && head->b != NULL */)
	{
		swap('A', head);
		swap('B', head);
		head->i = insert_node_b4(head->i, SS);
	}
}

void	push(char c, struct s_head *head)
{
	if (c == 'a' /* && head->a != NULL */)
	{
		head->a->prev->next = head->b;
		head->b = head->b->next;
		head->b->prev = head->b->prev->prev;
		head->b->prev->next = head->b;
		head->a->prev->next->next = head->a;
		head->a->prev->next->prev = head->a->prev;
		head->a->prev->next->next = head->a;
		head->a->prev = head->a->prev->next;
		head->a = head->a->prev;
		head->i = insert_node_b4(head->i, PA);
	}
	else if (c == 'b'/*  && head->b != NULL */)
	{
		head->b->prev->next = head->a;
		head->a = head->a->next;
		head->a->prev = head->a->prev->prev;
		head->a->prev->next = head->a;
		head->b->prev->next->next = head->b;
		head->b->prev->next->prev = head->b->prev;
		head->b->prev->next->next = head->b;
		head->b->prev = head->b->prev->next;
		head->b = head->b->prev;
		head->i = insert_node_b4(head->i, PB);
	}
}

void	rotate(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') /* && head->a != NULL */)
	{
		head->a = head->a->next;
		if (c == 'a')
			head->i = insert_node_b4(head->i, RA);
	}
	else if ((c == 'b' || c == 'B') /* && head->b != NULL */)
	{
		head->b = head->b->next;
		if (c == 'b')
			head->i = insert_node_b4(head->i, RB);
	}
	else if (c == 'c' /* && head->a != NULL && head->b != NULL */)
	{
		rotate('A', head);
		rotate('B', head);
		head->i = insert_node_b4(head->i, RR);
	}
}

void	revrotate(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') /* && head->a != NULL */)
	{
		head->a = head->a->prev;
		if (c == 'a')
			head->i = insert_node_b4(head->i, RRA);
	}
	else if ((c == 'b' || c == 'B') /* && head->b != NULL */)
	{
		head->b = head->b->prev;
		if (c == 'a')
			head->i = insert_node_b4(head->i, RRB);
	}
	else if (c == 'c' /* && head->a != NULL && head->b != NULL */)
	{
		revrotate('a', head);
		revrotate('b', head);
		head->i = insert_node_b4(head->i, RRR);
	}
}
