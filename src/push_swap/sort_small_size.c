//
// Created by dsalaman on 4/23/2021.
//

#include "push_swap.h"

void	apply_three_num_rules(t_node *stack_a, t_node **instr_queue)
{
	int	head;
	int	middle;
	int	tail;

	head = stack_a->data;
	middle = stack_a->prev->data;
	tail = stack_a->next->data;
	if ((head > middle && head < tail && middle < tail) ||
		(head > middle && head > tail && middle > tail) ||
		(head < middle && head < tail && middle > tail))
	{
		apply_instructions(&stack_a, NULL, SA);
		enqueue(instr_queue, SA);
	}
}
