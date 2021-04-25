//
// Created by diani on 4/24/2021.
//

#include "push_swap.h"

void	clean_stack(t_node **stack)
{
	if (*stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

void	reset_input_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->nodes = NULL;
	stack_b->nodes = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
}

void	reset_moves(t_moves **moves)
{
	*moves = (t_moves *)malloc(sizeof(t_moves));
	(*moves)->total = 0;
	(*moves)->inst = NULL;
}
