/*
** Created by dsalaman on 2021/04/22
*/

#include "push_swap.h"

t_node	*sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*instr_queue;

	instr_queue = NULL;
	if (stack_a->size == 3)
		apply_three_num_rules(stack_a->nodes, &instr_queue);
	else if (stack_a->size > 3)
	{
		insertion_sort_stack_b(stack_a, stack_b, &instr_queue);
		return_to_stack_a(stack_a, stack_b, &instr_queue);
	}
	sort_stack_a(stack_a, stack_b, &instr_queue);
	return instr_queue;
}

void	insertion_sort_stack_b(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	t_moves *moves;
	while (stack_a->size > 1)
	{
		moves = check_head_a(stack_a->nodes, stack_b);
		if (stack_a->size == 2 && is_positionable(stack_a->nodes->data,
			stack_b->nodes->data,  stack_b->nodes->next->data))
			break ;
		else if (moves->total != 0)
		{
			moves = best_moves(stack_a, stack_b, moves);
			apply_moves(moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
		}
		else
			apply_push_instruction(stack_a, stack_b, PB, instr_queue);
		free_moves(moves);
	}
}

void	apply_push_instruction(t_stack *from, t_stack *to, int inst,
			t_node **instr_queue)
{
	push_to_stack(&from->nodes, &to->nodes);
	enqueue(instr_queue, inst);
	from->size--;
	to->size++;
}

void	return_to_stack_a(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	int	last_a;
	int current_b;
	int next_b;

	last_a = stack_a->nodes->next->data;
	current_b =  stack_b->nodes->data;
	next_b =  stack_b->nodes->next->data;
	while (stack_b->size > 1 &&	!is_positionable(last_a, current_b, next_b))
	{
		apply_push_instruction(stack_b, stack_a, PA, instr_queue);
		current_b =  stack_b->nodes->data;
		next_b =  stack_b->nodes->next->data;
	}
	if ((stack_b->nodes != NULL && stack_a->size > 1) &&
		(!is_positionable(last_a, stack_a->nodes->data, next_b)))
	{
		apply_instructions(&stack_a->nodes, &stack_b->nodes, RRA);
		enqueue(instr_queue, RRA);
	}
	while (stack_b->nodes != NULL)
		apply_push_instruction(stack_b, stack_a, PA, instr_queue);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_node **instr_queue)
{
	int		i;
	t_node	*current_a;
	t_moves	*moves;

	i = 1;
	current_a = stack_a->nodes;
	while (current_a->data < current_a->prev->data)
	{
		i++;
		current_a = current_a->prev;
	}
	reset_moves(&moves);
	if (i <= stack_a->size / 2)
	{
		add_moves(moves, RA, i);
		apply_moves(moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
	}
	else if (i < stack_a->size)
	{
		add_moves(moves, RRA, stack_a->size - i);
		apply_moves(moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
	}
}
