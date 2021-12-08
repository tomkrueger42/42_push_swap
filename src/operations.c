/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:15 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/08 16:48:08 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char c, struct s_head *head)
{
	DATATYPE			tmp;

	if ((c == 'a' || c == 'A') && head->a != head->a->next /* && head->a != NULL */)
	{
		tmp = head->a->content;
		head->a->content = head->a->next->content;
		head->a->next->content = tmp;
		if (c == 'a')
			ft_putstr_fd("sa\n", FILE_DESCRIPTOR);
	}
	else if ((c == 'b' || c == 'B') && head->b != head->b->next /* && head->b != NULL */)
	{
		tmp = head->b->content;
		head->b->content = head->b->next->content;
		head->b->next->content = tmp;
		if (c == 'b')
			ft_putstr_fd("sb\n", FILE_DESCRIPTOR);
	}
	else if (c == 's')
	{
		swap('A', head);
		swap('B', head);
		ft_putstr_fd("ss\n", FILE_DESCRIPTOR);
	}
}

void	push(char c, struct s_head *head)
{
	if (c == 'a' /* && head->a != NULL */)
	{
		head->a = push_it(&head->b, &head->a);
		ft_putstr_fd("pa\n", FILE_DESCRIPTOR);
	}
	else if (c == 'b'/*  && head->b != NULL */)
	{
		head->b = push_it(&head->a, &head->b);
		ft_putstr_fd("pb\n", FILE_DESCRIPTOR);
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
	if ((c == 'a' || c == 'A') && head->a != NULL)
	{
		head->a = head->a->next;
		if (c == 'a')
			ft_putstr_fd("ra\n", FILE_DESCRIPTOR);
	}
	else if ((c == 'b' || c == 'B') && head->b != NULL)
	{
		head->b = head->b->next;
		if (c == 'b')
			ft_putstr_fd("rb\n", FILE_DESCRIPTOR);
	}
	else if (c == 'r')
	{
		rotate('A', head);
		rotate('B', head);
		ft_putstr_fd("rr\n", FILE_DESCRIPTOR);
	}
}

void	revrotate(char c, struct s_head *head)
{
	if ((c == 'a' || c == 'A') && head->a != NULL)
	{
		head->a = head->a->prev;
		if (c == 'a')
			ft_putstr_fd("rra\n", FILE_DESCRIPTOR);
	}
	else if ((c == 'b' || c == 'B') && head->b != NULL)
	{
		head->b = head->b->prev;
		if (c == 'b')
			ft_putstr_fd("rrb\n", FILE_DESCRIPTOR);
	}
	else if (c == 'r')
	{
		revrotate('A', head);
		revrotate('B', head);
		ft_putstr_fd("rrr\n", FILE_DESCRIPTOR);
	}
}
