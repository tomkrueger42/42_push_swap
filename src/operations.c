/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:15 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/07 20:07:40 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char c, struct s_head *head)
{
	struct s_content	*tmp;

	if ((c == 'a' || c == 'A') && head->a != head->a->next /* && head->a != NULL */)
	{
		tmp = head->a->content;
		head->a->content = head->a->next->content;
		head->a->next->content = tmp;
		if (c == 'a')
			head->i = insert_node_b4(head->i, create_content(0, SA));
	}
	else if ((c == 'b' || c == 'B') && head->b != head->b->next /* && head->b != NULL */)
	{
		tmp = head->b->content;
		head->b->content = head->b->next->content;
		head->b->next->content = tmp;
		if (c == 'b')
			head->i = insert_node_b4(head->i, create_content(0, SB));
	}
	else if (c == 's')
	{
		swap('A', head);
		swap('B', head);
		head->i = insert_node_b4(head->i, create_content(0, SS));
	}
}

void	push(char c, struct s_head *head)
{
	if (c == 'a' /* && head->a != NULL */)
	{
		head->a = push_it(&head->b, &head->a);
		head->i = insert_node_b4(head->i, create_content(0, PA));
	}
	else if (c == 'b'/*  && head->b != NULL */)
	{
		head->b = push_it(&head->a, &head->b);
		head->i = insert_node_b4(head->i, create_content(0, PB));
	}
}

struct s_node	*push_it(struct s_node **src, struct s_node **dst)
{
	if ((*dst) == NULL)
	{
		(*dst) = (*src);
		(*src) = (*src)->next;
		(*src)->prev = (*src)->prev->prev;
		(*src)->prev->next = (*src);
		(*dst)->next = (*dst);
		(*dst)->prev = (*dst);
	}
	else
	{
		(*dst)->prev->next = (*src);
		(*src) = (*src)->next;
		(*src)->prev = (*src)->prev->prev;
		(*src)->prev->next = (*src);
		(*dst)->prev->next->next = (*dst);
		(*dst)->prev->next->prev = (*dst)->prev;
		(*dst)->prev->next->next = (*dst);
		(*dst)->prev = (*dst)->prev->next;
		(*dst) = (*dst)->prev;
	}
	if ((*src) == (*dst))
		(*src) = NULL;
	return (*dst);
}

void	rotate(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') /* && head->a != NULL */)
	{
		head->a = head->a->next;
		if (c == 'a')
			head->i = insert_node_b4(head->i, create_content(0, RA));
	}
	else if ((c == 'b' || c == 'B') /* && head->b != NULL */)
	{
		head->b = head->b->next;
		if (c == 'b')
			head->i = insert_node_b4(head->i, create_content(0, RB));
	}
	else if (c == 'r')
	{
		rotate('A', head);
		rotate('B', head);
		head->i = insert_node_b4(head->i, create_content(0, RR));
	}
}

void	revrotate(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') /* && head->a != NULL */)
	{
		head->a = head->a->prev;
		if (c == 'a')
			head->i = insert_node_b4(head->i, create_content(0, RRA));
	}
	else if ((c == 'b' || c == 'B') /* && head->b != NULL */)
	{
		head->b = head->b->prev;
		if (c == 'a')
			head->i = insert_node_b4(head->i, create_content(0, RRB));
	}
	else if (c == 'r')
	{
		revrotate('A', head);
		revrotate('B', head);
		head->i = insert_node_b4(head->i, create_content(0, RRR));
	}
}
