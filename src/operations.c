/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:15 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 23:41:48 by tkruger          ###   ########.fr       */
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
