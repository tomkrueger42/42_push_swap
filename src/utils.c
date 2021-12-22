/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:43:18 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 23:50:14 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() returns the size of the list */
int	lst_size(t_node *start)
{
	t_node	*parser;
	int		i;

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

/* This f() inserts a new node before prev_node */
void	insert_node(int content, t_head *head)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (new == NULL)
		free_exit("Error\n", EXIT_FAILURE, head, NULL);
	if (head->a == NULL)
	{
		head->a = new;
		head->a->next = head->a;
		head->a->prev = head->a;
	}
	else
	{
		new->prev = head->a;
		new->next = head->a->next;
		new->prev->next = new;
		new->next->prev = new;
		head->a = new;
	}
	head->a->index = -1;
	head->a->content = content;
}

/* This f() frees the stack and puts an error message to FILE_DESCRIPTOR */
void	free_exit(char *errormsg, int exit_code, t_head *head, void *free_ptr)
{
	free_cdll(head->a);
	free_cdll(head->b);
	if (head != NULL)
		free(head);
	if (free_ptr != NULL)
		free(free_ptr);
	ft_putstr_fd(errormsg, FILE_DESCRIPTOR);
	exit(exit_code);
}

/* This f() deletes and frees each element of a circular doubly linked list*/
void	free_cdll(t_node *node)
{
	t_node	*tmp;

	if (node == NULL)
		return ;
	node->prev->next = NULL;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		ft_bzero(tmp, sizeof(t_node));
		free(tmp);
	}
}
