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
	return (instr_queue);
}

void	apply_three_num_rules(t_node *stack_a, t_node **instr_queue)
{
	int	head;
	int	middle;
	int	tail;

	head = stack_a->data;
	middle = stack_a->prev->data;
	tail = stack_a->next->data;
	if ((head > middle && head < tail && middle < tail)
		|| (head > middle && head > tail && middle > tail)
		|| (head < middle && head < tail && middle > tail))
	{
		apply_instructions(&stack_a, NULL, SA);
		enqueue(instr_queue, SA);
	}
}

void	insertion_sort_stack_b(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	t_moves	*moves;

	while (stack_a->size > 1)
	{
		if (stack_a->size == 2 && is_positionable(stack_a->nodes->data,
				stack_b->nodes->data, stack_b->nodes->next->data))
			break ;
		moves = check_head_a(stack_a->nodes, stack_b);
		if (moves->total > 0)
			moves = get_best_moves(stack_a, stack_b, moves);
		apply_moves(moves, stack_a, stack_b, instr_queue);
	}
}

void	return_to_stack_a(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	int	tail_a;
	int	current_b;
	int	tail_b;

	tail_a = stack_a->nodes->next->data;
	current_b = stack_b->nodes->data;
	tail_b = stack_b->nodes->next->data;
	while (stack_b->size > 1 && !is_positionable(tail_a, current_b, tail_b))
	{
		apply_push_instruction(stack_b, stack_a, PA, instr_queue);
		current_b = stack_b->nodes->data;
	}
	if (stack_b->nodes != NULL && stack_a->size > 1
		&& !is_positionable(tail_a, stack_a->nodes->data, tail_b))
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
		apply_moves(moves, stack_a, stack_b, instr_queue);
	}
	else if (i < stack_a->size)
	{
		add_moves(moves, RRA, stack_a->size - i);
		apply_moves(moves, stack_a, stack_b, instr_queue);
	}
	else
		free_moves(moves);
}
