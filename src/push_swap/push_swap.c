/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_node	*instr_queue;

	reset_input_push_swap(&stack_a, &stack_b);
	if (argc == 1)
		return (0);
	build_input_push_swap(argc - 1, argv, &stack_a);
	if (sorted(stack_a.nodes))
		exit(0);
	instr_queue = sort_stack(&stack_a, &stack_b);
	print_queue(instr_queue);
	return (0);
}
