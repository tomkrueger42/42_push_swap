/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/21 23:39:16 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_head	*head;

	head = ft_calloc(1, sizeof(t_head));
	if (head == NULL)
		return (0);
	if (argc < 2)
		free_exit("", EXIT_FAILURE, head, NULL);
	input_conversion(argc, argv, head);
	assign_indeces(head);
	if (lst_size(head->a) <= 5)
		sort_small(head);
	else
		(void)lis(head);
	merge_to_stack_a(head);
	free_exit("", EXIT_SUCCESS, head, NULL);
}

/* This f() converts the char **argv into a stack and checks for errors */
void	input_conversion(int argc, char **argv, t_head *head)
{
	char	**input;
	int		i;

	i = 0;
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = &argv[1];
	while (input[i] != NULL)
	{
		if (ft_isint(input[i]))
			insert_node(ft_atoi(input[i]), head);
		else
			free_exit("Error\n", EXIT_FAILURE, head, NULL);
		i++;
	}
	i = 0;
	if (argc == 2)
	{
		while (input[i] != NULL)
			free(input[i++]);
		free(input);
	}
	rotate('a', false, head);
}

/* This f() assigns indices for each element for easier comparison while
checking for doubles*/
void	assign_indeces(t_head *head)
{
	t_node	*parser;
	t_node	*lowest;
	int		i;
	int		j;

	i = 0;
	parser = head->a;
	while (i < lst_size(head->a))
	{
		lowest = NULL;
		j = 0;
		while (j < lst_size(head->a))
		{
			if ((lowest == NULL || lowest->content > parser->content)
				&& parser->index == -1)
				lowest = parser;
			else if (lowest != NULL && lowest->content == parser->content
				&& parser->index == -1 && ALLOW_DOUBLES == 0)
				free_exit("Error\n", EXIT_FAILURE, head, NULL);
			parser = parser->next;
			j++;
		}
		lowest->index = i;
		i++;
	}
}

/* This f() sorts small stacks */
void	sort_small(t_head *head)
{
	if (lst_size(head->a) == 3)
		sort_three(head, true);
	while (lst_size(head->a) > 3)
		push('b', true, head);
	sort_three(head, false);
}

/* This f() sorts stack a best when stack has <= 3 nodes. Subject somehow
requires it uses either 2 OR 3 instructions that's the reason for the
unnecessary sa instructions in the end */
void	sort_three(t_head *head, bool weird_requirements)
{
	int		i;

	i = 1;
	if (head->a->index < head->a->next->index && head->a->next->index
		> head->a->prev->index && head->a->index < head->a->prev->index && i++)
		swap('a', true, head);
	else if (head->a->index > head->a->next->index && head->a->next->index
		< head->a->prev->index && head->a->index < head->a->prev->index && i++)
		swap('a', true, head);
	else if (head->a->index > head->a->next->index && head->a->next->index
		> head->a->prev->index && head->a->index > head->a->prev->index && i++)
		swap('a', true, head);
	if (head->a->index > head->a->next->index && head->a->index
		> head->a->prev->index && i++)
		rotate('a', true, head);
	else if (head->a->index < head->a->next->index && head->a->index
		> head->a->prev->index && i++)
		revrotate('a', true, head);
	if (i <= 2 && weird_requirements == true)
	{
		swap('a', true, head);
		swap('a', true, head);
	}
}
