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

void 	apply_moves(t_moves *moves, t_node **stack_a, t_node **stack_b,
					t_node **instr_queue)
{
	t_map *temp;

	temp = moves->inst;
	while (temp != NULL)
	{
//		printf("moves --- %d\n", temp->value);
		while (temp->value > 0)
		{
			apply_instructions(stack_a, stack_b, temp->key);
//			printf("moves --- %d\n", temp->value);
			enqueue(instr_queue, temp->key);
//			printf("moves2 --- %d\n", temp->value);
			temp->value--;
		}
		temp = temp->next;
	}
	free_moves(moves);
}
