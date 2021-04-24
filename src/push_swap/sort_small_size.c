//
// Created by dsalaman on 4/23/2021.
//

#include "push_swap.h"

void	sort_three_num(t_node *stack_a, t_node *stack_b, t_node **instr_queue)
{
	if ((stack_a->data > stack_a->prev->data &&
	stack_a->data < stack_a->next->data &&
	stack_a->prev->data < stack_a->next->data) ||
	(stack_a->data > stack_a->prev->data &&
	stack_a->data > stack_a->next->data &&
	stack_a->prev->data > stack_a->next->data) ||
	(stack_a->data < stack_a->prev->data &&
	stack_a->data < stack_a->next->data &&
	stack_a->prev->data > stack_a->next->data))
	{
		apply_instructions(&stack_a, &stack_b, SA);
		enqueue(instr_queue, SA);
	}
}
