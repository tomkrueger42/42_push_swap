/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:43:18 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/15 19:01:43 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function returns the size of the list */
int	lst_size(struct s_node *start)
{
	struct s_node	*parser;
	int				i;

	i = 1;
	if (start == NULL)
		return (0);
	parser = start->next;
	while (parser != start)
	{
		parser = parser->next;
		i++;
	}
	return (i);
}

/* This function inserts a new node before prev_node */
struct s_node	*insert_node(struct s_node *prev_node, int content, int index)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	if (new == NULL)
		return (NULL);
	if (prev_node == NULL)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->prev = prev_node;
		new->next = prev_node->next;
		new->prev->next = new;
		new->next->prev = new;
	}
	new->index = index;
	new->content = content;
	return (new);
}

/* This function frees the stack and puts an error message to FILE_DESCRIPTOR */
void	free_exit(char *errormsg, int exit_code, struct s_head *head)
{
	if (exit_code == EXIT_FAILURE)
		print_go_brrrrr(head);
	free_cdll(head->a);
	free_cdll(head->b);
	free(head);
	ft_putstr_fd(errormsg, FILE_DESCRIPTOR);
	//system("leaks push_swap");
	exit(exit_code);
}

void	free_cdll(struct s_node *node)
{
	struct s_node	*tmp;

	if (node == NULL)
		return ;
	node->prev->next = NULL;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
