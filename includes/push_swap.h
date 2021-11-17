/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/16 19:53:40 by tomkrueger       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <time.h>

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
	struct s_content	*content;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

// inst is for instruction stack, value for sorting
typedef struct	s_content
{
	char		inst;
	DATATYPE	value;
}				t_content;

/* push_swap.c */

int					main(int argc, char **argv);
struct s_head		*input_conversion(int argc, char **argv, struct s_head *head);
void				print_go_brrrrr(struct s_head *head);
int					instruction_conversion(struct s_node *parse, struct s_node *head);

/* operations.c */

void				swap(char c, struct s_head *head);
void				push(char c, struct s_head *head);
struct s_node		*push_it(struct s_node **src, struct s_node **dst);
void				rotate(char c, struct s_head *head);
void				revrotate(char c, struct s_head *head);

/* list_handling.c */

int					lst_size(struct s_node *start);
struct s_content	*create_content(DATATYPE value, char inst);
struct s_node		*insert_node_b4(struct s_node *next_node, struct s_content *content);
int					error_free(char *errormsg, struct s_head *head);
void				free_node(struct s_node *node);

/* snake.c */

void				best_snake(struct s_head *head);
int					find_snake(struct s_node *start);

#endif