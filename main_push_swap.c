/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 21:53:12 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/13 21:53:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pop_sorted_stack(t_node **head)
{
	int		*data;
	t_node	*temp;

	temp = *head;
	if (*head == NULL)
		return (NULL);
	else if ((*head)->prev == NULL)
		*head = NULL;
	else
		*head = (*head)->prev;

	data = (int *)malloc(sizeof(int));
	*data = temp->data;
	free(temp);
	return (data);
}

int	node_size(t_node *head)
{
	int i;
	t_node *temp;
	t_node *tail;

	i = 0;
	temp = head;
	if (head == NULL)
		return (i);
	else
	{
		if (head->next != NULL)
			tail = head->next;
		while (temp != NULL && temp != tail)
		{
			temp = temp->prev;
			i++;
		}
		if (temp != NULL)
			i++;
	}
	return (i);
}

void	display_step(t_node *stack_a, t_node *stack_b, t_node *sorted_stack,
				  int count, int inst) //funcion de prueba
{
	int size_a;
	int size_b;
	int size_sorted;
	int i;

//	i = 0;
	size_a = node_size(stack_a);
	size_b = node_size(stack_b);
	size_sorted = node_size(sorted_stack);

	if (size_a >= size_b && size_a >= size_sorted)
		i = size_a;
	else if (size_b >= size_a && size_b >= size_sorted)
		i = size_b;
	else
		i = size_sorted;
	printf("---- Step %d------\n", count);
	while (i > 0)
	{
		printf("|");
		if (size_a == i)
		{
			printf(" %d |", stack_a->data);
			stack_a = stack_a->prev;
			size_a--;
		}
		else
			printf(" - |");
		if (size_b == i)
		{
			printf(" %d |", stack_b->data);
			stack_b = stack_b->prev;
			size_b--;
		}
		else
			printf(" - |");
		if (size_sorted == i)
		{
			printf(" %d |", sorted_stack->data);
			if (sorted_stack->prev != NULL)
				sorted_stack = sorted_stack->prev;
			size_sorted--;
		}
		else
			printf(" - |");
		printf("\n");
		i--;
	}
	printf("----------------- %d\n", inst);
}

void	display(t_node *head, char *name) //funcion de prueba
{
	t_node *temp;
	t_node *tail;

	temp = head;
	if (head == NULL)
		printf("Empty stack\n");
	else
	{
		if (head->next != NULL)
			tail = head->next;
		while (temp != NULL && temp != tail)
		{
			printf("%d\n", temp->data);
			temp = temp->prev;
		}
		if (temp != NULL)
			printf("%d\n", temp->data);
	}
	printf("---- %s \n", name);
}

void	display_qu(t_node *head, char *name) //funcion de prueba
{
	t_node *temp;
	t_node *tail;

	temp = head;
	if (head == NULL)
		printf("Empty queue\n");
	else
	{
		if (head->prev != NULL)
			tail = head->prev;
		while (temp != NULL && temp != tail)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
		if (temp != NULL)
			printf("%d\n", temp->data);
	}
	printf("---- %s \n", name);
}

int	swap_a(t_node **stack_a, t_node *sorted_stack) //quitar doble **,  cambiar el nombre check o algo asi
{
	if ((*stack_a)->prev->data == sorted_stack->data)
		return (1);
	return (0);
}

int	swap_b(t_node **stack_a, t_node **stack_b) //quitar doble **,  cambiar el nombre check o algo asi
{
	if ( *stack_b == NULL || (*stack_b)->prev->data !=  (*stack_b)->next->data)
		return (0);
	else if ((*stack_a)->data >  (*stack_b)->data &&
			(*stack_b)->data >  (*stack_b)->prev->data &&
			(*stack_a)->data >  (*stack_b)->next->data)
		return (1);
	else if ((*stack_a)->data >  (*stack_b)->data &&
			(*stack_b)->data <  (*stack_b)->prev->data &&
			(*stack_a)->data <  (*stack_b)->next->data)
		return (1);
	else if ((*stack_a)->data <  (*stack_b)->data &&
			(*stack_b)->data >  (*stack_b)->prev->data &&
			(*stack_a)->data <  (*stack_b)->next->data)
		return (1);
	return (0);
}

// Verify stack a is sorted, before starting
int	sorted(t_node *stack_a)
{
	t_node	*temp;

	if (!stack_a)
		return (0);
	temp = stack_a;
	while (temp->prev != stack_a)
	{
		if (temp->data > temp->prev->data)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int find_len_stack(t_node **head)
{
	t_node *stack;
	t_node *end;
	int len;

	len = 0;
	stack = *head;
	if (*head)
		end = (*head)->next;

	while (*head)
	{
		len++;
		if (stack == end)
			break;
		stack = stack->prev;
	}
	return (len);
}

// Get element from array returns a node H, P or N
t_node *get_node_from_index(int index, t_node *head_a)//incluir en header
{
	t_node *element;

	if (index == 0 || index == 1)
		element = head_a;
	else if (index == 2 || index == 3)
		element = head_a->prev;
	else
		element = head_a->next;
	return (element);
}

int choose_best_node_index(int index, int winner, t_node *head_a)// incluir en header
{
	t_node *left;
	t_node *right;

	left = get_node_from_index(index, head_a);
	right = get_node_from_index(winner, head_a);

	if (left->data < right->data)
		return (index);
	else
		return (winner);
}

// Get the element in stack A that requires less movements to push in stack B
int find_index_less_moves(int *moves, t_node *head_a) // incluir en header
{
	int index;
	int winner;

	index = 1;
	winner = 0;
	while (index < 6)
	{
		if ((winner == 0 || winner == 1) && moves[winner] == 0)
			break;
		else if (moves[index] < moves[winner] && moves[index] > -1)
			winner = index;
		else if (moves[index] == moves[winner])
			winner = choose_best_node_index(index,	winner, head_a);
		index++;
	}
	return (winner);
}


//find quantity of movements. First, we calculate differences between AH, AP and AN vs stack B
void set_moves_array(int *moves, t_node *stack_a, t_node *stack_b) // incluir en header
{
	t_node *temp;
	int res;

	temp = stack_b;
	while (temp)
	{
//		printf("quiero respirar!!!\n");

		res = stack_a->data - temp->data;
		if (res > 0 && moves[1] == 0)
			moves[0]++;
		else if (res < 0)
			moves[1]++;
		res = stack_a->prev->data - temp->data;
		if (res > 0 && moves[3] == 0)
			moves[2]++;
		else if (res < 0)
			moves[3]++;
		if(moves[4] != -1)
		{
			res = stack_a->next->data - temp->data;
			if (res > 0 && moves[5] == 0)
				moves[4]++;
			else if (res < 0)
				moves[5]++;
		}
		if (temp == stack_b->next)
			break;
		temp = temp->prev;
	}
}

// choose next move
int next_move(t_node *stack_a, t_node *stack_b, t_node *sorted_stack) // include en header
{
	int moves[6];
	int winner;

	printf("Hola\n");
	ft_bzero(moves, 6);
	if (stack_a->next->data < sorted_stack->data)
	{
		moves[4] = -1;
		moves[5] = -1;
	}
	set_moves_array(moves, stack_a, stack_b);
	winner = find_index_less_moves(moves, stack_a);
	printf("0-%d 1-%d 2-%d 3-%d 4-%d 5-%d\n", moves[0], moves[1], moves[2], moves[3], moves[4], moves[5] );
	printf("winner: %d, value %d\n", winner, moves[winner]);

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


//int sort_3(t_node **stack_a, t_node **stack_b, t_node *sorted_stack)
//{
//	int inst;
//
//	if ((((*stack_a)->data > (*stack_a)->prev->data &&
//		(*stack_a)->data > (*stack_a)->next->data) ||
//		((*stack_a)->data < (*stack_a)->prev->data &&
//		(*stack_a)->data < (*stack_a)->next->data)) &&
//		(*stack_a)->prev->data > (*stack_a)->next->data &&
//		swap_b(stack_a, stack_b))
//		inst = SS;
//	else if ((((*stack_a)->data > (*stack_a)->prev->data &&
//			(*stack_a)->data > (*stack_a)->next->data) ||
//			((*stack_a)->data < (*stack_a)->prev->data &&
//			(*stack_a)->data < (*stack_a)->next->data)) &&
//			(*stack_a)->prev->data > (*stack_a)->next->data)
//		inst = SA;
//	else if ((*stack_a)->data > (*stack_a)->prev->data &&
//			(*stack_a)->data < (*stack_a)->next->data)
//	{
//		inst = SA;
//		if ((*stack_a)->prev->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->next->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//	}
//	else if ((*stack_a)->data > (*stack_a)->prev->data &&
//			(*stack_a)->data > (*stack_a)->next->data)
//	{
//		inst = RA;
//		if ((*stack_a)->prev->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->next->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//	}
//	else if ((*stack_a)->data < (*stack_a)->prev->data &&
//			(*stack_a)->data > (*stack_a)->next->data)
//	{
//		inst = RRA;
//		if ((*stack_a)->next->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//		if ((*stack_a)->prev->data == sorted_stack->data)
//			pop_sorted_stack(&sorted_stack);
//	}
//	return (inst);
//}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*sorted_stack;
	t_node	*instr_queue;
	 int	inst;

	reset_input(&stack_a, &stack_b, &sorted_stack);
	if (argc == 1)
		return (0);
	build_input(argc - 1, argv, &stack_a, &sorted_stack); //revisar toca hacer dos veces ctrl + D
	if (sorted(stack_a))
		exit(0);
	sorted_stack = merge_sort(sorted_stack);

//	int len;
//	len = find_len_stack(&stack_a);
//	printf("len: %d\n", len);

//	display_step(stack_a, stack_b, sorted_stack,1, 1);

	int i = 0;
	i++;
//	display_step(stack_a, stack_b, sorted_stack, i, 0); //funcion prueba

	while (sorted_stack != NULL)
	{
		if (stack_a->next->data == stack_a->prev->prev->data &&
			((stack_a->data > stack_a->prev->data && stack_a->data > stack_a->next->data) ||
			 (stack_a->data < stack_a->prev->data && stack_a->data < stack_a->next->data)) &&
			stack_a->prev->data > stack_a->next->data && swap_b(&stack_a, &stack_b))
			inst = SS;
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				 ((stack_a->data > stack_a->prev->data && stack_a->data > stack_a->next->data) ||
				  (stack_a->data < stack_a->prev->data && stack_a->data < stack_a->next->data)) &&
				 stack_a->prev->data > stack_a->next->data)
		{
			printf("Ik ben een problem\n");
			inst = SA;
		}
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				stack_a->data > stack_a->prev->data &&
				stack_a->data < stack_a->next->data)
		{
			printf("<Me>\n");
			inst = SA;
			if (stack_a->prev->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->next->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
		}
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				stack_a->data > stack_a->prev->data &&
				stack_a->data > stack_a->next->data)
		{
			inst = RA;
			if (stack_a->prev->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->next->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
		}
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				stack_a->data < stack_a->prev->data &&
				stack_a->data > stack_a->next->data)
		{
			inst = RRA;
			if (stack_a->next->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
			if (stack_a->prev->data == sorted_stack->data)
				pop_sorted_stack(&sorted_stack);
		}
		else if (stack_a->data == sorted_stack->data)
		{
			inst = RA;
			pop_sorted_stack(&sorted_stack);
		}
		else if (stack_a->next->data == sorted_stack->data)
		{
			pop_sorted_stack(&sorted_stack);
			continue ;
		}
		else if (swap_a(&stack_a, sorted_stack) && swap_b(&stack_a, &stack_b))
			inst = SS;
		else if (swap_a(&stack_a, sorted_stack))
		{
			printf("Edgaaaaar!\n");
			inst = SA;
		}


		else if (stack_a->prev->data < stack_a->next->data &&
				stack_a->data < stack_a->next->data &&
				stack_a->next->data > sorted_stack->data &&
				stack_a->prev->data > sorted_stack->data)
			inst = RRA;
//		else if (stack_a->data < stack_a->prev->data &&
//				stack_a->next->data < stack_a->prev->data &&
//				stack_a->prev->data > sorted_stack->data)
//		{
//			printf("Jei\n");
//			inst = SA;
//		}
		else if (stack_b != NULL && stack_b->data == sorted_stack->data)
			inst = PA;
		else if (stack_b == NULL || stack_b->data == stack_b->prev->data)
			inst = PB;
		else if (stack_a->data < sorted_stack->data &&
				stack_b->data > stack_b->prev->data)
			inst = RB; //opcion de mejora, upgrade a  SB para SS o RR


		else if (swap_b(&stack_a, &stack_b))
			inst = SB;
		else
			inst = next_move(stack_a,stack_b,sorted_stack);

		apply_instructions(&stack_a, &stack_b, inst);
		enqueue(&instr_queue, inst);
		display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
		i++;  // remove, it is just for testing
	}
//	display_step(stack_a, stack_b, sorted_stack, i, inst);
	printf("Moves %d\n", i-1);
	return (0);
}

//int	main(int argc, char **argv)
//{
//	t_node	*stack_a;
//	t_node	*stack_b;
//	t_node	*sorted_stack;
//	t_node	*instr_queue;
//	int	inst;
//
//	reset_input(&stack_a, &stack_b, &sorted_stack);
//	if (argc == 1)
//		return (0);
//	build_input(argc - 1, argv, &stack_a, &sorted_stack); //revisar toca hacer dos veces ctrl + D
//	if (sorted(stack_a))
//		exit(0);
//	sorted_stack = merge_sort(sorted_stack);
//
////	int len;
////	len = find_len_stack(&stack_a);
////	printf("len: %d\n", len);
//
////	display_step(stack_a, stack_b, sorted_stack,1, 1);
//
//	int i = 0;
//	i++;
////	display_step(stack_a, stack_b, sorted_stack, i, 0); //funcion prueba
//
//	while (sorted_stack != NULL)
//	{
//		if (stack_a->next->data == stack_a->prev->prev->data &&
//			((stack_a->data > stack_a->prev->data &&
//			  stack_a->data > stack_a->next->data)||
//			 (stack_a->data < stack_a->prev->data &&
//			  stack_a->data < stack_a->next->data)) &&
//			stack_a->prev->data > stack_a->next->data &&
//			swap_b(&stack_a, &stack_b))
//			inst = SS;
//		else if (stack_a->next->data == stack_a->prev->prev->data &&
//				 ((stack_a->data > stack_a->prev->data &&
//				   stack_a->data > stack_a->next->data)||
//				  (stack_a->data < stack_a->prev->data &&
//				   stack_a->data < stack_a->next->data)) &&
//				 stack_a->prev->data > stack_a->next->data)
//			inst = SA;
//		else if (stack_a->next->data == stack_a->prev->prev->data &&
//				 stack_a->data > stack_a->prev->data &&
//				 stack_a->data < stack_a->next->data)
//		{
//			inst = SA;
//			if (stack_a->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->next->data == stack_a->prev->prev->data &&
//				 stack_a->data > stack_a->prev->data &&
//				 stack_a->data > stack_a->next->data)
//		{
//			inst = RA;
//			if (stack_a->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->next->data == stack_a->prev->prev->data &&
//				 stack_a->data < stack_a->prev->data &&
//				 stack_a->data > stack_a->next->data)
//		{
//			inst = RRA;
//			if (stack_a->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->data == sorted_stack->data)
//		{
//			inst = RA;
//			pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->next->data == sorted_stack->data)
//		{
//			pop_sorted_stack(&sorted_stack);
//			continue ;
//		}
//		else if (swap_a(&stack_a, sorted_stack) && swap_b(&stack_a, &stack_b))
//			inst = SS;
//		else if (swap_a(&stack_a, sorted_stack))
//			inst = SA;
//
//
//		else if (stack_a->prev->data < stack_a->next->data &&
//				 stack_a->data < stack_a->next->data &&
//				 stack_a->next->data > sorted_stack->data &&
//				 stack_a->prev->data > sorted_stack->data)
//			inst = RRA;
//		else if (stack_a->data < stack_a->prev->data &&
//				 stack_a->next->data < stack_a->prev->data &&
//				 stack_a->prev->data > sorted_stack->data)
//			inst = SA;
//		else if (stack_b != NULL && stack_b->data == sorted_stack->data)
//			inst = PA;
//		else if (stack_b == NULL || stack_b->data == stack_b->prev->data)
//			inst = PB;
//		else if (stack_a->data < sorted_stack->data &&
//				 stack_b->data > stack_b->prev->data)
//			inst = RB;
//		else if (stack_a->data < stack_b->data &&
//				 stack_b->data > stack_b->next->data &&
//				 stack_b->data > stack_b->prev->data &&
//				 stack_a->data < stack_b->prev->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RB;
//		else if (stack_a->data < stack_b->data &&
//				 stack_b->data > stack_b->next->data &&
//				 stack_b->data > stack_b->prev->data &&
//				 stack_a->data > stack_b->prev->data &&
//				 stack_a->data < stack_b->next->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RB;
//		else if (stack_a->data > stack_b->data &&
//				 stack_b->data > stack_b->prev->data &&
//				 stack_b->data > stack_b->next->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RB;
//		else if (stack_a->data > stack_b->data &&
//				 stack_b->data < stack_b->prev->data &&
//				 stack_b->data > stack_b->next->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RB;
//		else if (stack_a->data > stack_b->data && //chequear esto (25mar)
//				 stack_b->data < stack_b->prev->data &&
//				 stack_b->data < stack_b->next->data &&
//				 stack_a->data < stack_b->next->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RB; // si quito este codigo, segfault
//		else if (stack_a->data < stack_b->data &&
//				 stack_b->data < stack_b->prev->data &&
//				 stack_b->data > stack_b->next->data &&
//				 stack_a->data < stack_b->next->data &&
//				 stack_b->prev->data != stack_b->next->data)
//			inst = RRB;
//		else if (swap_b(&stack_a, &stack_b))
//			inst = SB;
//		else
//			inst = PB;
//		apply_instructions(&stack_a, &stack_b, inst);
//		enqueue(&instr_queue, inst);
//		display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
//		i++;  // remove, it is just for testing
//	}
////	display_step(stack_a, stack_b, sorted_stack, i, inst);
//	printf("Moves %d\n", i-1);
//	return (0);
//}