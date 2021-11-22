/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:38:17 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/22 18:05:10 by tkruger          ###   ########.fr       */
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

	big_snake_ahhh(head);
	//print_go_brrrrr(head);
	merge_to_stack_a(head);
	print_go_brrrrr(head);
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
			head->a = insert_node_b4(NULL, create_content(ft_atoi(*argv), 0));
		else
			head->a = insert_node_b4(head->a, create_content(ft_atoi(*argv), 0));
		argv++;
	}
	rotate('A', head);
	argv = NULL;
	/* if (check_doubles(head))
		return (NULL); */
	return (head);
}
/* 
int	check_doubles(struct s_head *head)
{
	int	i;
	int	j;
	struct s_node	*node1;
	struct s_node	*node2;
	

	i = 0;
	j = 1;
	while (i < lst_size(head->a))
	{
		while (j < lst_size(head->a))
		{
			
		}
	}
} */

/* This function prints out stacks a & b and the instruction stack to stdout */
void	print_go_brrrrr(struct s_head *head)
{
	struct s_node *a_parser;
	struct s_node *b_parser;

	a_parser = head->a != NULL ? head->a->next : NULL;
	b_parser = head->b != NULL ? head->b->next : NULL;
	printf("stack a: | stack b:\n");
	if (head->a && head->b)
		printf("%i\t | %i\n", head->a->content->value, head->b->content->value);
	else if (head->a)
		printf("%i\n", head->a->content->value);
	else if (head->b)
		printf("\t | %i\n", head->b->content->value);
	while (a_parser != head->a && b_parser != head->b && a_parser != NULL && b_parser != NULL)
	{
		printf("%i \t | %i\n", a_parser->content->value, b_parser->content->value);
		a_parser = a_parser->next;
		b_parser = b_parser->next;
	}
	while (a_parser != head->a && a_parser != NULL)
	{
		printf("%i\n", a_parser->content->value);
		a_parser = a_parser->next;
	}
	while (b_parser != head->b && b_parser != NULL)
	{
		printf("\t | %i\n", b_parser->content->value);
		b_parser = b_parser->next;
	}
	printf("%i instructions\n---------------\n", put_inst(head));
}

/* This function loops through head->i and sends elements to instruction_conversion() */
int	put_inst(struct s_head *head)
{
	struct s_node	*parser;
	int				i;

	parser = head->i->next;
	i = 0;
	while (parser != NULL && (parser != head->i->next || i == 0))
	{
		//instruction_conversion(parser);
		parser = parser->next;
		i++;
	}
	return (i);
}

/* This function converts int back into instructions and writes them to the fd */
void	instruction_conversion(struct s_node *parser)
{
		if (parser->content->inst == SA)
			ft_putstr_fd("sa\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == SB)
			ft_putstr_fd("sb\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == SS)
			ft_putstr_fd("ss\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == PA)
			ft_putstr_fd("pa\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == PB)
			ft_putstr_fd("pb\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RA)
			ft_putstr_fd("ra\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RB)
			ft_putstr_fd("rb\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RR)
			ft_putstr_fd("rr\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RRA)
			ft_putstr_fd("rra\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RRB)
			ft_putstr_fd("rrb\n", FILE_DESCRIPTOR);
		else if (parser->content->inst == RRR)
			ft_putstr_fd("rrr\n", FILE_DESCRIPTOR);
}
