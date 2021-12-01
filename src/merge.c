/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:29 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/01 01:27:09 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_to_stack_a(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	while (head->b != NULL)
		push_sorted('a', head);
	parser = head->a;
	while (parser->index > parser->prev->index)
	{
		parser = parser->next;
		i++;
	}
	i = i <= lst_size(head->a) / 2 ? i : -(lst_size(head->a) - i);
	while (i > 0 && i--)
		rotate('a', head);
	while (i < 0 && i++)
		revrotate('a', head);
}
