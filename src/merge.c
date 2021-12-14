/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:29 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/14 01:20:40 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_to_stack_a(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	i = 0;
	while (head->b != NULL)
	{
		i = find_right_position(head->b, head->a);
		i = i <= lst_size(head->a) / 2 ? i : -(lst_size(head->a) - i);
		while (i > 0 && i--)
			rotate('a', head);
		while (i < 0 && i++)
			revrotate('a', head);
		push('a', head);
	}
	i = 0;
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
