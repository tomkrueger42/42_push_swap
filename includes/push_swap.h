/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/03 21:36:33 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <time.h>

/* defined because valgrind requires it */

# define INT32_MAX 2147483647

/* change the following for sorting other datatypes */

# define DATATYPE int

# ifndef MIN_VALUE
#  define MIN_VALUE INT_MIN
# endif

# ifndef MAX_VALUE
#  define MAX_VALUE INT_MAX
# endif

# define FILE_DESCRIPTOR 1

/* operation to int conversion table */

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

/* structs */

typedef struct	s_head
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*i;
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
struct s_head		*input_conversion(int argc, char **argv, struct s_head *head);
void				assign_indeces(struct s_head *head);
void				print_go_brrrrr(struct s_head *head);
int					put_inst(struct s_head *head);
void				instruction_conversion(struct s_node *parse);

/* operations.c */

void				swap(char c, struct s_head *head);
void				push(char c, struct s_head *head);
struct s_node		*push_it(struct s_node **src, struct s_node **dst);
void				rotate(char c, struct s_head *head);
void				revrotate(char c, struct s_head *head);

/* list_handling.c */

int					lst_size(struct s_node *start);
struct s_node		*insert_node_b4(struct s_node *next_node, DATATYPE content, int index);
int					error_free(char *errormsg, struct s_head *head);

/* lis.c */

int					lis(struct s_head *head);
void				make_this_efficient(struct s_node *lis_start, struct s_head *head);
int					increasing_subsequence(struct s_node *lis_start);
int					part_of_lis(struct s_node *lis_start, struct s_node *node);
int					value_at(struct s_node *node, int pos);

/* sort.c */

void				push_sorted(char c, struct s_head *head);
int					find_right_position(char c, struct s_node *node, struct s_head *head);
int					lis_break(char c, struct s_node *node);

/* merge.c */

void				merge_to_stack_a(struct s_head *head);

#endif
