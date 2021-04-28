/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

t_node	*sort_checker(t_node **stack_a, t_node **stack_b)
{
	int		*inst;
	t_node	*instr_queue;

	instr_queue = get_instructions();
	while (peek(instr_queue))
	{
		inst = deque(&instr_queue);
		apply_instructions(stack_a, stack_b, *inst);
		free(inst);
	}
	return (instr_queue);
}

int	is_sorted(t_node *stack_a, t_node *stack_b, t_node *sorted)
{
	if (stack_b != NULL)
		return (0);
	while (sorted != NULL)
	{
		if (stack_a->data != sorted->data)
			return (0);
		stack_a = stack_a->prev;
		sorted = sorted->prev;
	}
	return (1);
}

void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*sorted = NULL;
}
