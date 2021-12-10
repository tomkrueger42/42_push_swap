/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/10 19:06:34 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_head	*head;

	head = malloc(sizeof(head));
	if (head == NULL)
		return (0);
	input_conversion(argc, argv, head);
	assign_indeces(head);
	(void)lis(head);
	merge_to_stack_a(head);
	free_exit("", EXIT_SUCCESS, head);
}

void	input_conversion(int argc, char **argv, struct s_head *head)
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
		if (ft_strncmp(input[i], ft_itoa(ft_atoi(input[i])), ft_strlen(input[i])) != 0)
			free_exit("Error\n", EXIT_FAILURE, head);
		else
			head->a = insert_node(head->a, ft_atoi(input[i]), -1);
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

/* This function assigns indices for each element for easier comparison
while checking for doubles*/
void	assign_indeces(struct s_head *head)
{
	struct s_node	*parser;
	struct s_node	*lowest;
	int				i;
	int				j;

	i = 0;
	parser = head->a;
	while (i < lst_size(head->a))
	{
		lowest = NULL;
		j = 0;
		while (j < lst_size(head->a))
		{
			if ((lowest == NULL || lowest->content > parser->content) && parser->index == -1)
				lowest = parser;
			else if (lowest != NULL && lowest->content == parser->content && parser->index == -1 && ALLOW_DOUBLES == 0)
				free_exit("Error\n", EXIT_FAILURE, head);
			parser = parser->next;
			j++;
		}
		lowest->index = i;
		i++;
	}
}
