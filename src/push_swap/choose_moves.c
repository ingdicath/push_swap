/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

// Get element from array returns a node Head, Prev or Next

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
		if ((winner == 0 || winner == 1) && moves[winner] == 0)
			break ;
		else if (moves[index] < moves[winner] && moves[index] > -1)
			winner = index;
		else if (moves[index] == moves[winner])
			winner = choose_best_node_index(index, winner, head_a);
		index++;
	}
	return (winner);
}

// Find the amount of movements.
// First, we calculate differences between A-Head, A-Prev and A-Next vs stack 'b'
// temp is for current value
// biggest finds breakpoint

void	set_moves_array(int *moves, t_node *stack_a, t_node *stack_b) //acortar
{
	t_node	*temp;
	int		res;
	int		biggest;

	temp = stack_b;
	biggest = temp->data;
	while (temp)
	{
		res = stack_a->data - temp->data;
		if (biggest > temp->data)
			res *= -1;
		if (biggest > stack_a->data)
			res *= -1;
//		if (res > 0 && moves[1] == 0)
		if (res > 0)
			moves[0]++;
		else if (res < 0)
			moves[1]++;
		res = stack_a->prev->data - temp->data;
		if (biggest > temp->data)
			res *= -1;
		if (biggest > stack_a->data)
			res *= -1;
//		if (res > 0 && moves[3] == 0)
		if (res > 0)
			moves[2]++;
		else if (res < 0)
			moves[3]++;
		if (moves[4] != -1)
		{
			res = stack_a->next->data - temp->data;
			if (biggest > temp->data)
				res *= -1;
			if (biggest > stack_a->data)
				res *= -1;
			if (res > 0)
//			if (res > 0 && moves[5] == 0)
				moves[4]++;
			else if (res < 0)
				moves[5]++;
		}
		if (temp == stack_b->next)
			break ;
		temp = temp->prev;
	}
}

// Choose next move

int	next_move(t_node *stack_a, t_node *stack_b, t_node *sorted_stack)
{
	int	moves[6];
	int	winner;

//	printf("Hola\n"); //quitar despues
	ft_bzero(moves, 6);
	if (stack_a->next->data < sorted_stack->data)
	{
		moves[4] = -1;
		moves[5] = -1;
	}
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
		return (SA);
	else
		return (RRA);
}
