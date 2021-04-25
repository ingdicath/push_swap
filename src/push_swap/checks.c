/*
** Created by dsalaman on 2021/04/18
*/

#include "push_swap.h"

t_moves *check_head_a(t_node *head_a, t_stack *stack_b)
{
	t_moves *moves;
	int moves_b;

	reset_moves(&moves);
	moves_b = check_first_half_b(head_a->data, stack_b);
	if (moves_b == 0)
		add_moves(moves, PB, 0);
	else if (moves_b == -1)
	{
		moves_b = check_second_half_b(head_a->data, stack_b);
		add_moves(moves, RRB, moves_b);
	}
	else
		add_moves(moves, RB, moves_b);
	return (moves);
}

// moves_b returns the position to insert element from stack 'a' to stack 'b'
// starting from the top

int check_first_half_b(int current_a, t_stack *stack_b)
{
	int		moves_b;
	t_node	*current_b;

	if (stack_b->size == 0 || stack_b->size == 1)
		return (0);
	current_b = stack_b->nodes;
	moves_b = 0;
	while (moves_b <= stack_b->size / 2)
	{
		if (is_positionable(current_a, current_b->data, current_b->next->data))
			return (moves_b);
		moves_b++;
		current_b = current_b->prev;
	}
	return (-1);
}

// 'moves_b' returns the position to insert element from stack 'a' to stack 'b'
// starting from the tail

int	check_second_half_b(int current_a, t_stack *stack_b)
{
	int moves_b;
	t_node *current_b;

	moves_b = 1;
	current_b = stack_b->nodes->next;
	while (moves_b <= stack_b->size / 2)
	{
		if (is_positionable(current_a, current_b->data, current_b->next->data))
			return (moves_b);
		moves_b++;
		current_b = current_b->next;
	}
	return (-1);
}

void	check_first_half_a(int current_a, t_stack *stack_b, int index,
			t_moves **moves)
{
	int moves_b;

	reset_moves(moves);
	moves_b = check_first_half_b(current_a, stack_b);
	if (moves_b == 0)
		add_moves(*moves, RA, index);
	else if (moves_b == -1)
	{
		moves_b = check_second_half_b(current_a, stack_b);
		add_moves(*moves, RA, index);
		add_moves(*moves, RRB, moves_b);
	}
	else if (moves_b == index)
		add_moves(*moves, RR, index);
	else if (moves_b > index)
	{
		add_moves(*moves, RR, index);
		add_moves(*moves, RB, moves_b - index);
	}
	else if (moves_b < index)
	{
		add_moves(*moves, RR, moves_b);
		add_moves(*moves, RA, index - moves_b);
	}
}

void	check_second_half_a(int current_a, t_stack *stack_b, int index,
			t_moves **moves)
{
	int moves_b;

	reset_moves(moves);
	moves_b = check_second_half_b(current_a, stack_b);
	if (moves_b == 0)
		add_moves(*moves, RRA, index);
	else if (moves_b == -1)
	{
		moves_b = check_first_half_b(current_a, stack_b);
		add_moves(*moves, RRA, index);
		add_moves(*moves, RB, moves_b);
	}
	else if (moves_b == index)
		add_moves(*moves, RRR, index);
	else if (moves_b > index)
	{
		add_moves(*moves, RRR, index);
		add_moves(*moves, RRB, moves_b - index);
	}
	else if (moves_b < index)
	{
		add_moves(*moves, RRR, moves_b);
		add_moves(*moves, RRA, index - moves_b);
	}
}
