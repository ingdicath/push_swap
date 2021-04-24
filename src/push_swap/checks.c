/*
** Created by dsalaman on 2021/04/18
*/

#include "push_swap.h"

// moves_b returns the position to insert element from stack 'a' to stack 'b'
// starting from the top

int check_first_half_b(t_node *current_a, t_stack *stack_b)
{
	int moves_b;
	t_node *current_b;

	moves_b = 0;
	if (stack_b->size == 0 || stack_b->size == 1)
		return (moves_b);
	current_b = stack_b->nodes;
	while (moves_b <= stack_b->size / 2)
	{
		if ((current_a->data > current_b->data &&
			(current_b->data > current_b->next->data ||
			current_a->data < current_b->next->data)) ||
			(current_b->next->data < current_b->data &&
			current_a->data < current_b->data &&
			current_a->data < current_b->next->data))
			return (moves_b);
		else
		{
			moves_b++;
			current_b = current_b->prev;
		}
	}
	return (-1);
}

// moves_b returns the position to insert element from stack 'a' to stack 'b'
// starting from the tail

int check_second_half_b(t_node *current_a, t_stack *stack_b)
{
	int moves_b;
	t_node *current_b;

	moves_b = 1;
	current_b = stack_b->nodes->next;
	while (moves_b <= stack_b->size / 2)
	{
		if ((current_a->data > current_b->data &&
			(current_b->data > current_b->next->data ||
			current_a->data < current_b->next->data)) ||
			(current_b->next->data < current_b->data &&
			current_a->data < current_b->data &&
			current_a->data < current_b->next->data))
			return (moves_b);
		else
		{
			moves_b++;
			current_b = current_b->next;
		}
	}
	return (-1);
}

t_moves *check_head_a(t_node *head_a, t_stack *stack_b)
{
	t_moves *moves;
	int moves_b;

	reset_moves(&moves);
	moves_b = check_first_half_b(head_a, stack_b);
	if (moves_b == 0)
		add_moves(moves, PB, 0);
	else if (moves_b == -1)
	{
		moves_b = check_second_half_b(head_a, stack_b);
		add_moves(moves, RRB, moves_b);
	}
	else
		add_moves(moves, RB, moves_b);
	return (moves);
}

// i starts 1 because of head

void check_moves_a(t_stack *stack_a, t_stack *stack_b, t_moves **current_moves)
{
	int i;
	int moves_b;
	t_node *up_a;
	t_node *down_a;
	t_moves *moves;

	up_a = stack_a->nodes->prev;
	down_a = stack_a->nodes->next;
	i = 1;
	reset_moves(&moves);
	while (i < (*current_moves)->total && i < (stack_a->size / 2))
	{
		moves_b = check_first_half_b(up_a, stack_b);
		if (moves_b == 0)
			add_moves(moves, RA, i);
		else if (moves_b == -1)
		{
			moves_b = check_second_half_b(up_a, stack_b);
			add_moves(moves, RA, i);
			add_moves(moves, RRB, moves_b);
		}
		else if (moves_b == i)
			add_moves(moves, RR, i);
		else if (moves_b > i)
		{
			add_moves(moves, RR, i);
			add_moves(moves, RB, moves_b - i);
		}
		else if (moves_b < i)
		{
			add_moves(moves, RR, moves_b);
			add_moves(moves, RA, i - moves_b);
		}
		if ((*current_moves)->total > moves->total)
		{
			free_moves(*current_moves);
			*current_moves = moves;
		}
//		free_moves(moves);
		reset_moves(&moves);
		moves_b = check_second_half_b(down_a, stack_b);
		if (moves_b == 0)
			add_moves(moves, RRA, i);
		else if (moves_b == -1)
		{
			moves_b = check_first_half_b(down_a, stack_b);
			add_moves(moves, RRA, i);
			add_moves(moves, RB, moves_b);
		}
		else if (moves_b == i)
			add_moves(moves, RRR, i);
		else if (moves_b > i)
		{
			add_moves(moves, RRR, i);
			add_moves(moves, RRB, moves_b - i);
		}
		else if (moves_b < i)
		{
			add_moves(moves, RRR, moves_b);
			add_moves(moves, RRA, i - moves_b);
		}
		if ((*current_moves)->total > moves->total)
		{
			free_moves(*current_moves);
			*current_moves = moves;
			reset_moves(&moves);
		}
		i++;
		up_a = up_a->prev;
		down_a = down_a->next;
	}
}
