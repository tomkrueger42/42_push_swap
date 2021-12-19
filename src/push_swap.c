/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/19 21:29:01 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_head	*head;

	head = ft_calloc(1, sizeof(t_head));
	if (head == NULL)
		return (0);
	input_conversion(argc, argv, head);
	assign_indeces(head);
	(void)lis(head);
	merge_to_stack_a(head);
	free_exit("", EXIT_SUCCESS, head);
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
		if (ft_strncmp(input[i], ft_itoa(ft_atoi(input[i])),
				ft_strlen(input[i])) != 0)
			free_exit("Error\n", EXIT_FAILURE, head);
		else
			insert_node(ft_atoi(input[i]), head);
		i++;
	}
	i = 0;
	if (argc == 2)
	{
		while (input[i] != NULL)
			free(input[i++]);
		free(input);
	}
	rotate('A', head);
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
				free_exit("Error\n", EXIT_FAILURE, head);
			parser = parser->next;
			j++;
		}
		lowest->index = i;
		i++;
	}
}

/* This f() merges both stacks onto stack a sorted */
void	merge_to_stack_a(t_head *head)
{
	t_node	*parser;
	int		i;

	while (head->b != NULL)
	{
		efficient_rotation(NULL, head->b, head->a, head);
		push('a', head);
	}
	i = 0;
	parser = head->a;
	while (parser->index > parser->prev->index)
	{
		parser = parser->next;
		i++;
	}
	if (i > lst_size(head->a) / 2)
		i = -i;
	while (i > 0 && i--)
		rotate('a', head);
	while (i < 0 && i++)
		revrotate('a', head);
}
