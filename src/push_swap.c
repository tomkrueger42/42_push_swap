/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/01 02:15:38 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	struct s_head	*head;

	head = malloc(sizeof(head));
	if (head == NULL || !input_conversion(argc, argv, head))
		return (0);
	head->i = NULL;

	assign_indeces(head);
	(void)lis(head);
	merge_to_stack_a(head);
	//print_go_brrrrr(head);
	(void)put_inst(head);
	//error_free("does it free?\nlet's see!\n", head);
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
			error_free("bad input :(\n", head);
			return (NULL);
		}
		else if (head->a == NULL)
			head->a = insert_node_b4(NULL, ft_atoi(*argv), -1);
		else
			head->a = insert_node_b4(head->a, ft_atoi(*argv), -1);
		argv++;
	}
	rotate('A', head);
	argv = NULL;
	return (head);
}

/* This function assigns indices for each element for easier comparison */
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
			if ((lowest == NULL || lowest->content >= parser->content) && parser->index == -1)
				lowest = parser;
			parser = parser->next;
			j++;
		}
		lowest->index = i;
		i++;
	}
}

/* This function prints out stacks a & b and the instruction stack to stdout */
void	print_go_brrrrr(struct s_head *head)
{
	struct s_node *a_parser;
	struct s_node *b_parser;

	a_parser = head->a != NULL ? head->a->next : NULL;
	b_parser = head->b != NULL ? head->b->next : NULL;
	printf("stack a: | stack b:\n");
	if (head->a && head->b)
		printf("%i\t | %i\n", head->a->content, head->b->content);
	else if (head->a)
		printf("index: %i; %i\n", head->a->index, head->a->content);
	else if (head->b)
		printf("\t | %i\n", head->b->content);
	while (a_parser != head->a && b_parser != head->b && a_parser != NULL && b_parser != NULL)
	{
		printf("%i \t | %i\n", a_parser->content, b_parser->content);
		a_parser = a_parser->next;
		b_parser = b_parser->next;
	}
	while (a_parser != head->a && a_parser != NULL)
	{
		printf("index: %i; %i\n", a_parser->index, a_parser->content);
		a_parser = a_parser->next;
	}
	while (b_parser != head->b && b_parser != NULL)
	{
		printf("\t | %i\n", b_parser->content);
		b_parser = b_parser->next;
	}
	printf("%i instructions\n---------------\n", lst_size(head->i));
}

/* This function loops through head->i and sends elements to instruction_conversion() */
int	put_inst(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	if (head->i == NULL)
		return (0);
	parser = head->i->next;
	i = 0;
	while (parser != NULL && (parser != head->i->next || i == 0))
	{
		instruction_conversion(parser);
		parser = parser->next;
		i++;
	}
	return (i);
}

/* This function converts int back into instructions and writes them to the fd */
void	instruction_conversion(struct s_node *parser)
{
		if (parser->index == SA)
			ft_putstr_fd("sa\n", FILE_DESCRIPTOR);
		else if (parser->index == SB)
			ft_putstr_fd("sb\n", FILE_DESCRIPTOR);
		else if (parser->index == SS)
			ft_putstr_fd("ss\n", FILE_DESCRIPTOR);
		else if (parser->index == PA)
			ft_putstr_fd("pa\n", FILE_DESCRIPTOR);
		else if (parser->index == PB)
			ft_putstr_fd("pb\n", FILE_DESCRIPTOR);
		else if (parser->index == RA)
			ft_putstr_fd("ra\n", FILE_DESCRIPTOR);
		else if (parser->index == RB)
			ft_putstr_fd("rb\n", FILE_DESCRIPTOR);
		else if (parser->index == RR)
			ft_putstr_fd("rr\n", FILE_DESCRIPTOR);
		else if (parser->index == RRA)
			ft_putstr_fd("rra\n", FILE_DESCRIPTOR);
		else if (parser->index == RRB)
			ft_putstr_fd("rrb\n", FILE_DESCRIPTOR);
		else if (parser->index == RRR)
			ft_putstr_fd("rrr\n", FILE_DESCRIPTOR);
}
