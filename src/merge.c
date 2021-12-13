/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:29 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/13 23:09:09 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_to_stack_a(struct s_head *head)
{
	struct s_node	*parser;
	int				count;
	int				i;

	i = 0;
	while (head->b != NULL)
	{
		count = find_right_position('a', head->b, head);
		count = count <= lst_size(head->a) / 2 ? count : -(lst_size(head->a) - count);
		while (count > 0 && count--)
			rotate('a', head);
		while (count < 0 && count++)
			revrotate('a', head);
		push('a', head);
	}
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
