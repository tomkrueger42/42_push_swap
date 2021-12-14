/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:48:39 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/14 01:17:30 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function finds the right position for *node in *head */
int	find_right_position(struct s_node *node, struct s_node *dst)
{
	int				i;
	int				size;

	i = 0;
	size = lst_size(dst);
	while ((dst != node || i == 0))
	{
		if (size <= 1 || (dst->prev->index < node->index && node->index < dst->index) || ((dst->prev->index < node->index || node->index < dst->index) && dst->index < dst->prev->index))
			return (i);
		dst = dst->next;
		i++;
	}
	return (0);
}
