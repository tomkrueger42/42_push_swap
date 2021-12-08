/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/08 18:27:50 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_head	*head;

	head = malloc(sizeof(head));
	if (head == NULL || !input_conversion(argc, argv, head))
		return (0);

	assign_indeces(head);
	(void)lis(head);
	merge_to_stack_a(head);
	free_exit("", EXIT_SUCCESS, head);
	//system("leaks push_swap");
}

struct s_head	*input_conversion(int argc, char **argv, struct s_head *head)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	while (*argv != NULL)
	{
		if (ft_strncmp(*argv, ft_itoa(ft_atoi(*argv)), ft_strlen(*argv)) != 0)
		{
			free_exit("Error\n", EXIT_FAILURE, head);
		}
		else if (head->a == NULL)
		{
			head->a = insert_node(NULL, ft_atoi(*argv), -1);
		}
		else
		{
			head->a = insert_node(head->a, ft_atoi(*argv), -1);
		}
		argv++;
	}
	rotate('A', head);
	argv = NULL;
	return (head);
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
