/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/17 01:33:48 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libs/libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

/* change the following for manipulating the program */

# define DATATYPE int
# define ALLOW_DOUBLES 0
# define FILE_DESCRIPTOR 1

/* further macros */

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define DIFF(a, b) (a > b ? a - b : b - a)
#define X_ROT(a, b) (a < b ? a : -b)
#define ABS(a) (a >= 0 ? a : -a)

/* structs */

typedef struct	s_head
{
	t_node	*a;
	t_node	*b;
}				t_head;

typedef struct	s_node
{
	int					content;
	int					index;
	t_node		*next;
	t_node		*prev;
}				t_node;

typedef struct	s_rotation
{
	int				r_src;
	int				rr_src;
	int				r_dst;
	int				rr_dst;
	int				x_src;
	int				x_dst;
	int				m_r_src;
	int				m_rr_src;
	int				m_r_dst;
	int				m_rr_dst;
	int				m_x_src;
	int				m_x_dst;
}				t_rotation;

/* push_swap.c */

int				main(int argc, char **argv);
void			input_conversion(int argc, char **argv, t_head *head);
void			assign_indeces(t_head *head);
void			merge_to_stack_a(t_head *head);

/* print.c */

void			print_go_brrrrr(t_head *head);
/* void			ridin_the_rollercoaster(t_rotation *rollercoaster, bool print_min);
 */
/* operations.c */

int				swap(char c, t_head *head);
void			push(char c, t_head *head);
t_node			*push_it(t_node **src, t_node **dst);
void			rotate(char c, t_head *head);
void			revrotate(char c, t_head *head);

/* list_handling.c */

int				lst_size(t_node *start);
void			insert_node(int content, t_head *head);
int				find_right_position(t_node *node, t_node *dst);
void			free_exit(char *errormsg, int exit_code, t_head *head);
void			free_cdll(t_node *node);

/* lis.c */

void			lis(t_head *head);
int				increasing_subsequence(t_node *lis_start);
int				part_of_lis(t_node *lis_start, t_node *node);

/* efficient_rotation.c */

void			efficient_rotation(t_node *lis_start, t_node *src, t_node *dst, t_head *head);
void			set_r(t_rotation *r, t_node *src, t_node *dst);
void			best_rotate(t_rotation *r, t_node *src, t_head *head);
void			best_revrotate(t_rotation *r, t_node *src, t_head *head);
void			best_x_rotate(t_rotation *r, t_node *src, t_head *head);

/* sort.c */


/* merge.c */


#endif
