/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:41:07 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 23:48:46 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* This f() assists with the swap operation */
void	swap_it(t_node *node)
{
	node->prev->next = node->next;
	node->next->next->prev = node;
	node->next->prev = node->prev;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
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
