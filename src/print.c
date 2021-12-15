#include "../includes/push_swap.h"

/* This function prints out stacks a & b and the instruction stack to stdout */
void	print_go_brrrrr(struct s_head *head)
{
	struct s_node *a_parser;
	struct s_node *b_parser;

	a_parser = head->a != NULL ? head->a->next : NULL;
	b_parser = head->b != NULL ? head->b->next : NULL;
	printf("stack a: | stack b:\n");
	if (head->a && head->b)
		printf("%i\t | %i\n", head->a->index, head->b->index);
	else if (head->a)
		printf("%i\n", head->a->index);
	else if (head->b)
		printf("\t | %i\n", head->b->index);
	while (a_parser != head->a && b_parser != head->b && a_parser != NULL && b_parser != NULL)
	{
		printf("%i \t | %i\n", a_parser->index, b_parser->index);
		a_parser = a_parser->next;
		b_parser = b_parser->next;
	}
	while (a_parser != head->a && a_parser != NULL)
	{
		printf("%i\n", a_parser->index);
		a_parser = a_parser->next;
	}
	while (b_parser != head->b && b_parser != NULL)
	{
		printf("\t | %i\n", b_parser->index);
		b_parser = b_parser->next;
	}
	printf("\n------------------------------\n");
}

void	ridin_the_rollercoaster(struct s_rotation *rollercoaster, bool print_best)
{
	printf("rotate_src: %i\n", 			rollercoaster->rotate_src);
	printf("rev_rotate_src: %i\n", 		rollercoaster->rev_rotate_src);
	printf("rotate_dst: %i\n", 			rollercoaster->rotate_dst);
	printf("rev_rotate_dst: %i\n", 		rollercoaster->rev_rotate_dst);
	printf("x_src: %i\n", 				rollercoaster->x_src);
	printf("x_dst: %i\n", 				rollercoaster->x_dst);
	printf("rotate_all: %i\n", 			rollercoaster->rotate_all);
	printf("rev_rotate_all: %i\n", 		rollercoaster->rev_rotate_all);
	printf("delta: %i\n", 				rollercoaster->delta);
	printf("rev_delta: %i\n", 			rollercoaster->rev_delta);
	if (print_best == false)
		return ;
	printf("best_rotate_src: %i\n", 	rollercoaster->best_rotate_src);
	printf("best_rev_rotate_src: %i\n", rollercoaster->best_rev_rotate_src);
	printf("best_rotate_dst: %i\n", 	rollercoaster->best_rotate_dst);
	printf("best_rev_rotate_dst: %i\n", rollercoaster->best_rev_rotate_dst);
	printf("best_x_src: %i\n", 			rollercoaster->best_x_src);
	printf("best_x_dst: %i\n", 			rollercoaster->best_x_dst);
	printf("best_rotate_all: %i\n", 	rollercoaster->best_rotate_all);
	printf("best_rev_rotate_all: %i\n", rollercoaster->best_rev_rotate_all);
	printf("best_delta: %i\n", 			rollercoaster->best_delta);
	printf("best_rev_delta: %i\n", 		rollercoaster->best_rev_delta);
}