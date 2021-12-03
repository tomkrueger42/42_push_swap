/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:43:18 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/03 02:47:55 by tomkrueger       ###   ########.fr       */
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

/* This function inserts a new node b4 prev_node */
struct s_node	*insert_node_b4(struct s_node *prev_node, int content, int index)
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
int	error_free(char *errormsg, struct s_head *head)
{
	struct s_node	*node;
	
	while (head->a != NULL)
	{
		printf("head->a: %p\n", head->a);
		printf("h->a->n: %p\n", head->a->next);
		node = head->a;
		head->a = head->a->next;
		node->next = NULL;
		node->prev = NULL;
		free(node);
	}
	if (head->a != NULL)
	{
		head->a->next = NULL;
		head->a->prev = NULL;
		free(head->a);
	}
	while (head->b != NULL && head->b->next != NULL && head->b != head->b->next)
	{
		printf("head->b: %p\n", head->b);
		printf("h->b->n: %p\n", head->b->next);
		head->b = head->b->next;
		head->b->prev->next = NULL;
		head->b->prev->prev = NULL;
		free(head->b->prev);
	}
	if (head->b != NULL)
	{
		head->b->next = NULL;
		head->b->prev = NULL;
		free(head->b);
	}
	ft_putstr_fd(errormsg, FILE_DESCRIPTOR);
	return (1);
}

/* This function frees a node and its content element */
/* void	free_node(struct s_node *node)
{
	if (node != NULL)
	{
		if (node->content != NULL)
			free(node->content);
		node->content = NULL;
		free(node);
		node->prev = NULL;
		node->next = NULL;
	}
}
 */