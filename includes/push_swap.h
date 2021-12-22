/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:29:02 by tkruger           #+#    #+#             */
/*   Updated: 2021/12/22 14:03:17 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* includes */

# include "../libs/libft/includes/libft.h"

/* change the following for manipulating the program */

# define ALLOW_DOUBLES 0
# define FILE_DESCRIPTOR 1

/* structs */

typedef struct s_head
{
	struct s_node	*a;
	struct s_node	*b;
}	t_head;

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_rotation
{
	int				pos;
	int				src;
	int				dst;
	bool			x;
}				t_rotation;

/* push_swap.c */

int				main(int argc, char **argv);
void			input_conversion(int argc, char **argv, t_head *head);
void			assign_indeces(t_head *head);
void			sort_three(t_head *head, bool weird_requirements);
void			sort_small(t_head *head);

/* print.c */

void			print_go_brrrrr(t_head *head);
void			print_rotations(t_rotation *rotations);

/* operations.c */

void			swap(char c, bool print, t_head *head);
void			push(char c, bool print, t_head *head);
void			rotate(char c, bool print, t_head *head);
void			revrotate(char c, bool print, t_head *head);

/* operation_utils.c */

void			swap_it(t_node *node);
t_node			*push_it(t_node **src, t_node **dst);

/* list_handling.c */

int				lst_size(t_node *start);
void			insert_node(int content, t_head *head);
void			free_exit(char *errormsg, int exit_code, t_head *head,
					void *free_ptr);
void			free_cdll(t_node *node);

/* sort.c */

void			lis(t_head *head);
int				increasing_subsequence(t_node *lis_start);
int				part_of_lis(t_node *lis_start, t_node *node);
int				find_right_position(t_node *node, t_node *dst);
void			merge_to_stack_a(t_head *head);

/* efficient_rotation.c */

void			efficient_rotation(t_node *lis_start, t_node *src, t_node *dst,
					t_head *head);
void			calc_r(t_rotation *r, t_rotation *bench, t_node *src,
					t_node *dst);
void			set_r(t_rotation *r, int r_src, int r_dst, bool r_x);
void			benchmark(t_rotation *r, t_rotation *bench);
void			best_rotate(t_rotation *r, char src, char dst, t_head *head);

#endif
