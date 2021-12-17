/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:43:18 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/17 01:15:31 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This f() returns the size of the list */
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

/* This f() inserts a new node before prev_node */
void	insert_node(int content, struct s_head *head)
{
	struct s_node	*new;

	new = ft_calloc(1, sizeof(struct s_node));
	if (new == NULL)
		free_exit("malloc failure\n", EXIT_FAILURE, head);
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

/* This f() finds the right position for *node in stack *dst */
int	find_right_position(struct s_node *node, struct s_node *dst)
{
	int	i;

	i = 0;
	if (lst_size(dst) <= 1)
		return (0);
	while (true)
	{
		if ((dst->prev->index < node->index && node->index < dst->index)
			|| ((dst->prev->index < node->index || node->index < dst->index)
			&& dst->index < dst->prev->index))
			return (i);
		dst = dst->next;
		i++;
	}
	return (0);
}

/* This f() frees the stack and puts an error message to FILE_DESCRIPTOR */
void	free_exit(char *errormsg, int exit_code, struct s_head *head)
{
	//printf("head: %p\n", head);
	free_cdll(head->a);
	free_cdll(head->b);
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
		//printf("%p\n", node);
		tmp = node->next;
		node->next = NULL;
		node->prev = NULL;
		free(node);
		node = NULL;
		node = tmp;
	}
}
