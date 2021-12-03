/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:43:18 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/02 00:23:53 by tomkrueger       ###   ########.fr       */
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
	if (head->a && 0)
		printf("cause of unused parameter error msg\n");
	/* while (head->a->next != NULL)
	{
		//printf("head->a: %p\n", head->a);
		//printf("prev->a: %p\n", head->a->next);
		//printf("prev->a: %p\n", head->a->prev);
		head->a = head->a->next;
		//printf("head->a: %p\n", head->a);
		//printf("prev->a: %p\n", head->a->next);
		//printf("prev->a: %p\n", head->a->prev);
		//free_node(head->a->prev);
	}
	while (head->b != NULL)
	{
		head->b = head->b->next;
		free_node(head->b->prev);
	}
	while (head->i != NULL)
	{
		head->i = head->i->next;
		free_node(head->i->prev);
	}
	if (head != NULL)
	{
		free(head);
		head = NULL;
	} */
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