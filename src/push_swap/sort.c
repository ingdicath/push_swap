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
		pass_to_stack_a(stack_a, stack_b, &instr_queue);
	}
	sort_stack_a(stack_a, stack_b, &instr_queue);
	return instr_queue;
}
void	apply_push_instruction(t_stack *from, t_stack *to, int inst,
			t_node **instr_queue)
{
	push_to_stack(&from->nodes, &to->nodes);
	enqueue(instr_queue, inst);
	from->size--;
	to->size++;
}

void	insertion_sort_stack_b(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	t_moves *moves;
	while (stack_a->nodes != stack_a->nodes->next)
	{
		moves = check_head_a(stack_a->nodes, stack_b);
		if (moves->total == 0)
			apply_push_instruction(stack_a, stack_b, PB, instr_queue);
		else
		{
			check_moves_a(stack_a, stack_b, &moves);
			apply_moves(moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
		}
	}
}

void	pass_to_stack_a(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	int last_a;

	last_a = stack_a->nodes->data;
	while (stack_b->nodes->data != stack_b->nodes->next->data &&
	!( (last_a > stack_b->nodes->data &&
		(stack_b->nodes->data > stack_b->nodes->next->data ||
		last_a < stack_b->nodes->next->data)) ||
		(stack_b->nodes->next->data < stack_b->nodes->data &&
		last_a < stack_b->nodes->data &&
		last_a < stack_b->nodes->next->data))
		)
	{
		apply_instructions(&stack_a->nodes, &stack_b->nodes, PA);
		enqueue(instr_queue, PA);
	}
	stack_a->size = find_len_stack(stack_a->nodes);
	if (stack_b->nodes != NULL && stack_a->size > 1)
	{
		apply_instructions(&stack_a->nodes, &stack_b->nodes, RRA);
		enqueue(instr_queue, RRA);
	}
	while (stack_b->nodes != NULL)
	{
		apply_instructions(&stack_a->nodes, &stack_b->nodes, PA);
		enqueue(instr_queue, PA);
	}
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_node **instr_queue)
{
	int		i;
	t_node	*temp;
	t_moves	*moves;

	i = 1;
	stack_a->size = find_len_stack(stack_a->nodes);
	temp = stack_a->nodes;
	while (temp->data < temp->prev->data)
	{
		i++;
		temp = temp->prev;
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
