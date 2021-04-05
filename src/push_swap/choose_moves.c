/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

// Get element from array returns a node Head, Prev or NexT

t_node	*get_node_from_index(int index, t_node *head_a)
{
	t_node	*element;

	if (index == 0 || index == 1)
		element = head_a;
	else if (index == 2 || index == 3)
		element = head_a->prev;
	else
		element = head_a->next;
	return (element);
}

int	choose_best_node_index(int index, int winner, t_node *head_a)
{
	t_node	*left;
	t_node	*right;
	if (winner == 0 || winner == 1)
		return (winner);
	left = get_node_from_index(index, head_a);
	right = get_node_from_index(winner, head_a);
	if (left->data < right->data)
		return (index);
	else
		return (winner);
}

// Get the element from stack A that requires less movements to push in stack B

int	find_index_less_moves(int *moves, t_node *head_a)
{
	int	index;
	int	winner;

	index = 1;
	winner = 0;
	while (index < 6)
	{
		if (moves[index] < moves[winner] && moves[index] > -1)
			winner = index;
		else if (moves[index] == moves[winner])
			winner = choose_best_node_index(index, winner, head_a);
		index++;
	}
	return (winner);
}

// Find the amount of movements.
// First, we calculate differences between A-Head, A-Prev and A-Next vs stack 'b'

void	set_moves_array(int *moves, t_node *stack_a, t_node *stack_b) //acortar
{
	t_node	*current;

	current = stack_b;
	while (current)
	{
//		if ((stack_a->data > current->data) != (current->data > stack_b->data))
//			moves[0]++;
//		else
//			moves[1]++;
//		if (moves[2] != -1)
//		{
//			if ((stack_a->prev->data > current->data) != (current->data > stack_b->data))
//				moves[2]++;
//			else
//				moves[3]++;
//		}
//		if (moves[4] != -1)
//		{
//			if ((stack_a->next->data > current->data) != (current->data > stack_b->data))
//				moves[4]++;
//			else
//				moves[5]++;
//		}

// PARA XOR
		if (stack_a->data > stack_b->data)
		{
			if ((stack_a->data > current->data) != (current->data > stack_b->data))
				moves[0]++;
			else
				moves[1]++;
		}
// PARA XNOR
		else
		{
			if ((stack_a->data > current->data) == (current->data > stack_b->data))
				moves[0]++;
			else
				moves[1]++;
		}
		if (moves[2] != -1)
		{
			if (stack_a->prev->data > stack_b->data)
			{
				if ((stack_a->prev->data > current->data) != (current->data > stack_b->data))
					moves[2]++;
				else
					moves[3]++;
			}
			else
			{
				if ((stack_a->prev->data > current->data) == (current->data > stack_b->data))
					moves[2]++;
				else
					moves[3]++;
			}
		}
		if (moves[4] != -1)
		{
			if(stack_a->next->data > stack_b->data)
			{
				if ((stack_a->next->data > current->data) != (current->data > stack_b->data))
					moves[4]++;
				else
					moves[5]++;
			}
			else
			{
				if ((stack_a->next->data > current->data) == (current->data > stack_b->data))
					moves[4]++;
				else
					moves[5]++;
			}
		}
		if (current == stack_b->next)
			break ;
		current = current->prev;
	}
}

// Choose next move

int	next_move(t_node *stack_a, t_node *stack_b, t_node *sorted_stack)
{
	int	moves[6];
	int	winner;

//	ft_bzero(moves, 6);
	moves[0]=0; // revisarrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
	moves[1]=0;
	if (stack_a->next->data < sorted_stack->data)
	{
		moves[4] = -1;
		moves[5] = -1;
	}
	else
	{
		moves[4] = 1; //dejarlo por ahora con 1 (abril 4)
		moves[5] = 1; // 1 include movement to push to the other stack
	}
	if (stack_a->prev->data < sorted_stack->data)
	{
		moves[2] = -1; // revisarrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
		moves[3] = -1;
	}
	else
	{
		moves[2] = 1; // revisarrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
		moves[3] = 1; //revisar
	}

//	printf("before 0-%d 1-%d 2-%d 3-%d 4-%d 5-%d\n", moves[0], moves[1], moves[2], moves[3], moves[4], moves[5]); //quitar despues
	set_moves_array(moves, stack_a, stack_b);
	winner = find_index_less_moves(moves, stack_a);
//	printf("0-%d 1-%d 2-%d 3-%d 4-%d 5-%d\n", moves[0], moves[1], moves[2], moves[3], moves[4], moves[5]); //quitar despues
//	printf("winner: %d, value %d\n", winner, moves[winner]); //quitar despues
	if ((winner == 0 || winner == 1) && moves[winner] == 0 )
		return (PB);
	else if (winner == 0)
		return (RB);
	else if (winner == 1)
		return (RRB);
	else if (winner == 2 || winner == 3)
	{
		return (SA);
	}
	else if (winner == 5 && moves[winner] != 0)
		return (RRR);
	else
		return (RRA);
}
