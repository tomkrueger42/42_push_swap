/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:06:29 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/23 15:18:25 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_to_stack_a(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	parser = head->a;
	i = -1;
	while (head->b != NULL)
		push_sorted('a', head);
	while (parser->content->value < parser->next->content->value)
	{
		parser = parser->next;
		i++;
	}
	/* printf("i = %i\n", i);
	printf("a = %i\n", lst_size(head->a)); */
	i = i < lst_size(head->a) / 2 ? i : -(lst_size(head->a) - i);
	/* printf("i = %i\n", i); */
	while (i > 0 && i--)
		rotate('a', head);
	while (i < 0 && i++)
		revrotate('a', head);
}
