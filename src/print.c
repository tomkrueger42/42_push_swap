#include "../includes/push_swap.h"

/* This f() prints out stacks a & b and the instruction stack to stdout */
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

/* This f() prints out the rotations stored in struct s_rotation *r */
void	print_r(struct s_rotation *r, bool print_min)
{
	printf("r_src: %i\n", 		r->r_src);
	printf("rr_src: %i\n", 		r->rr_src);
	printf("r_dst: %i\n", 		r->r_dst);
	printf("rr_dst: %i\n", 		r->rr_dst);
	printf("x_src: %i\n", 		r->x_src);
	printf("x_dst: %i\n", 		r->x_dst);
	if (print_min == false)
		return ;
	printf("m_r_src: %i\n",		r->m_r_src);
	printf("m_rr_src: %i\n",	r->m_rr_src);
	printf("m_r_dst: %i\n",		r->m_r_dst);
	printf("m_rr_dst: %i\n",	r->m_rr_dst);
	printf("m_x_src: %i\n",		r->m_x_src);
	printf("m_x_dst: %i\n",		r->m_x_dst);
}