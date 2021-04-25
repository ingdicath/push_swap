/*
** Created by dsalaman on 2021/04/21
*/

#include "push_swap.h"

void	free_moves(t_moves *moves)
{
	t_map *temp;

	while (moves->inst != NULL)
	{
		temp = moves->inst->next;
		free(moves->inst);
		moves->inst = temp;
	}
}

void	add_moves(t_moves *moves, int inst, int quantity)
{
	t_map *new_inst;

	new_inst = create_map_element(inst, quantity);
	if (moves->inst == NULL)
	{
		moves->total = quantity;
		moves->inst = new_inst;
	}
	else
	{
		moves->total += quantity;
		moves->inst->next = new_inst;
	}
}

// empieza a aplicar los movimientos para cada valor en cada stack

void 	apply_moves(t_moves *moves, t_stack *stack_a, t_stack *stack_b,
					t_node **instr_queue)
{
	t_map *curr_inst;

	curr_inst = moves->inst;
	while (curr_inst != NULL)
	{
		if (curr_inst->value == 0 && curr_inst->key == PB)
			apply_push_instruction(stack_a, stack_b, PB, instr_queue);
		while (curr_inst->value > 0)
		{
			apply_instructions(&stack_a->nodes, &stack_b->nodes, curr_inst->key);
			enqueue(instr_queue, curr_inst->key);
			curr_inst->value--;
		}
		curr_inst = curr_inst->next;
	}
	free_moves(moves);
}

t_moves	*choose_moves(t_moves *current, t_moves *new)
{
	t_moves *moves;

	if (current->total > new->total)
	{
		moves = new;
		free_moves(current);
	}
	else
	{
		moves = current;
		free_moves(new);
	}
	return (moves);
}

// i starts 1 because of head
// we receive current moves from head, return the best move

t_moves	*get_best_moves(t_stack *stack_a, t_stack *stack_b, t_moves *current_moves)
{
	int	i;
	t_node *up_a;
	t_node *down_a;
	t_moves *moves;

	up_a = stack_a->nodes->prev;
	down_a = stack_a->nodes->next;
	i = 1;
	while (i < current_moves->total && i < (stack_a->size / 2))
	{
		check_first_half_a(up_a->data, stack_b, i, &moves);
		current_moves = choose_moves(current_moves, moves);
		check_second_half_a(down_a->data, stack_b, i, &moves);
		current_moves = choose_moves(current_moves, moves);
		i++;
		up_a = up_a->prev;
		down_a = down_a->next;
	}
	return (current_moves);
}
