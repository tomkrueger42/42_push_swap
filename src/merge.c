/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:29 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/22 17:39:18 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_to_stack_a(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	parser = head->a;
	i = 1;
	while (head->b != NULL)
		push_sorted('a', head);
	while (parser->content->value > parser->prev->content->value)
	{
		parser = parser->next;
		i++;
	}
	i = i < lst_size(head->a) / 2 ? i : -(lst_size(head->a) - i);
	while (i < 0 && i++)
		rotate('a', head);
	while (i > 0 && i--)
		revrotate('a', head);
}
