/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomkrueger <tomkrueger@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/15 20:01:04 by tomkrueger       ###   ########.fr       */
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

/* macro to return the smaller one of two values */

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define DIFF(a, b) (a > b ? a - b : b - a)
#define ABS(a) (a >= 0 ? a : -a)

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

typedef struct	s_rotation
{
	int				rotate_src;
	int				rev_rotate_src;
	int				rotate_dst;
	int				rev_rotate_dst;
	int				x_src;
	int				x_dst;
	int				rotate_all;
	int				rev_rotate_all;
	int				delta;
	int				rev_delta;
	int				best_rotate_src;
	int				best_rev_rotate_src;
	int				best_rotate_dst;
	int				best_rev_rotate_dst;
	int				best_x_src;
	int				best_x_dst;
	int				best_rotate_all;
	int				best_rev_rotate_all;
	int				best_delta;
	int				best_rev_delta;
}				t_rotation;

/* push_swap.c */

int				main(int argc, char **argv);
void			input_conversion(int argc, char **argv, struct s_head *head);
void			assign_indeces(struct s_head *head);

/* print.c */

void			print_go_brrrrr(struct s_head *head);
void			ridin_the_rollercoaster(struct s_rotation *rollercoaster, bool print_best);

/* operations.c */

void			swap(char c, struct s_head *head);
void			push(char c, struct s_head *head);
struct s_node	*push_it(struct s_node **src, struct s_node **dst);
void			rotate(char c, struct s_head *head);
void			revrotate(char c, struct s_head *head);

/* list_handling.c */

int				lst_size(struct s_node *start);
struct s_node	*insert_node(struct s_node *next_node, DATATYPE content, int index);
void			free_exit(char *errormsg, int exit_code, struct s_head *head);
void			free_cdll(struct s_node *node);

/* lis.c */

void			lis(struct s_head *head);

void			efficient_rotation(struct s_node *lis_start, struct s_node *src, struct s_node *dst, struct s_head *head);
void			set_rotations(struct s_rotation *rollercoaster, struct s_node *src, struct s_node *dst);
void			benchmark_rotations(struct s_rotation *rollercoaster);
void			rock_n_roll(struct s_rotation *rollercoaster, struct s_node *src, struct s_head *head);


int				increasing_subsequence(struct s_node *lis_start);
int				part_of_lis(struct s_node *lis_start, struct s_node *node);

/* sort.c */

int				find_right_position(struct s_node *node, struct s_node *dst);

/* merge.c */

void			merge_to_stack_a(struct s_head *head);

#endif
