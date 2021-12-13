/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/13 23:10:42 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libs/libft/includes/libft.h"
# include <stdio.h>

/* change the following for manipulating the program */

# define DATATYPE int
# define ALLOW_DOUBLES 0
# define FILE_DESCRIPTOR 1

/* structs */

typedef struct	s_head
{
	struct s_node	*a;
	struct s_node	*b;
}				t_head;

typedef struct	s_node
{
	DATATYPE			content;
	int					index;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

/* push_swap.c */

int					main(int argc, char **argv);
void				input_conversion(int argc, char **argv, struct s_head *head);
void				assign_indeces(struct s_head *head);

/* print.c */

void				print_go_brrrrr(struct s_head *head);

/* operations.c */

void				swap(char c, struct s_head *head);
void				push(char c, struct s_head *head);
struct s_node		*push_it(struct s_node **src, struct s_node **dst);
void				rotate(char c, struct s_head *head);
void				revrotate(char c, struct s_head *head);

/* list_handling.c */

int					lst_size(struct s_node *start);
struct s_node		*insert_node(struct s_node *next_node, DATATYPE content, int index);
void				free_exit(char *errormsg, int exit_code, struct s_head *head);
void				free_cdll(struct s_node *node);

/* lis.c */

int					lis(struct s_head *head);
void				make_this_efficient(struct s_node *lis_start, struct s_head *head);
int					increasing_subsequence(struct s_node *lis_start);
int					part_of_lis(struct s_node *lis_start, struct s_node *node);

/* sort.c */

int					find_right_position(char c, struct s_node *node, struct s_head *head);
int					lis_break(char c, struct s_node *node);

/* merge.c */

void				merge_to_stack_a(struct s_head *head);

#endif
