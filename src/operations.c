/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:15 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 17:30:00 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() executes the swap operation */
void	swap(char c, bool print, t_head *head)
{
	if (c == 'a')
	{
		head->a = head->a->next;
		swap_it(head->a->prev);
		if (print)
			ft_putstr_fd("sa\n", FILE_DESCRIPTOR);
	}
	else if (c == 'b')
	{
		head->b = head->b->next;
		swap_it(head->b->prev);
		if (print)
			ft_putstr_fd("sb\n", FILE_DESCRIPTOR);
	}
	if (c == 's')
	{
		swap('a', false, head);
		swap('b', false, head);
		ft_putstr_fd("ss\n", FILE_DESCRIPTOR);
	}
}

void	swap_it(t_node *node)
{
	node->prev->next = node->next;
	node->next->next->prev = node;
	node->next->prev = node->prev;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
}

/* This f() executes the push operation */
void	push(char c, bool print, t_head *head)
{
	if (c == 'a')
	{
		head->a = push_it(&head->b, &head->a);
		if (print)
			ft_putstr_fd("pa\n", FILE_DESCRIPTOR);
	}
	else if (c == 'b')
	{
		head->b = push_it(&head->a, &head->b);
		if (print)
			ft_putstr_fd("pb\n", FILE_DESCRIPTOR);
	}
}

/* This f() assists with the push operation */
t_node	*push_it(t_node **src, t_node **dst)
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

/* This f() executes the rotate operation */
void	rotate(char c, bool print, t_head *head)
{
	if (c == 'a' && head->a != NULL)
	{
		head->a = head->a->next;
		if (print)
			ft_putstr_fd("ra\n", FILE_DESCRIPTOR);
	}
	else if (c == 'b' && head->b != NULL)
	{
		head->b = head->b->next;
		if (print)
			ft_putstr_fd("rb\n", FILE_DESCRIPTOR);
	}
	else if (c == 'r')
	{
		rotate('a', false, head);
		rotate('b', false, head);
		ft_putstr_fd("rr\n", FILE_DESCRIPTOR);
	}
}

/* This f() executes the revrotate operation */
void	revrotate(char c, bool print, t_head *head)
{
	if (c == 'a' && head->a != NULL)
	{
		head->a = head->a->prev;
		if (print)
			ft_putstr_fd("rra\n", FILE_DESCRIPTOR);
	}
	else if (c == 'b' && head->b != NULL)
	{
		head->b = head->b->prev;
		if (print)
			ft_putstr_fd("rrb\n", FILE_DESCRIPTOR);
	}
	else if (c == 'r')
	{
		revrotate('a', false, head);
		revrotate('b', false, head);
		ft_putstr_fd("rrr\n", FILE_DESCRIPTOR);
	}
}
