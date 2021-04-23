/*
** Created by dsalaman on 2021/04/22
*/

#include "push_swap.h"

void	build_input_push_swap(int size, char **argv, t_stack *stack_a)
{
	t_node *sorted;

	sorted = NULL;
	build_input(size,argv,&stack_a->nodes,&sorted);
	stack_a->size = find_len_stack(stack_a->nodes);
	merge_sort(sorted);
	clean_stack(&sorted);
}
