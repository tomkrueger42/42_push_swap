/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/11/03 17:06:47 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "libft.h"
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

// when sorting strings, operations can't be stored in content :/
typedef struct	s_node
{
	DATATYPE		content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/* push_swap.c */

int					main(int argc, char **argv);
struct s_head		*input_conversion(int argc, char **argv, struct s_head *head);
void				print_go_brrrrr(struct s_head *head);
int					instruction_conversion(struct s_node *parse, struct s_node *head);

/* operations.c */

void				swap(char c, struct s_head *head);
void				push(char c, struct s_head *head);
void				rotate(char c, struct s_head *head);
void				revrotate(char c, struct s_head *head);

/* list_handling.c */

void				*insert_node_b4(struct s_node *next_node, DATATYPE content);
int					error_free(char *errormsg, struct s_head *head);
void				free_node(struct s_node *node);

#endif
