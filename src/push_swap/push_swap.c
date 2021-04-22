/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

void sort_stack_b(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
		t_node **instr_queue)
{
	while (stack_a->nodes != stack_a->nodes->next)
	{
		*moves = check_head_a(stack_a->nodes, stack_b);
		if ((*moves)->total == 0)
		{
			//			display_moves(moves);
			apply_instructions(&stack_a->nodes, &stack_b->nodes, PB);
			//			display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
			enqueue(instr_queue, PB);
			stack_a->size--;
			stack_b->size++;
		}
		else
		{
			check_moves_a(stack_a, stack_b, moves);
			//			display_moves(moves);
			apply_moves(*moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
		}
	}
}

void pass_to_stack_a(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
		t_node **instr_queue)
{
	*moves = check_head_a(stack_a->nodes, stack_b);
	if ((*moves)->total > 0)
	{
		apply_moves(*moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
		//		display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
	}
	while (stack_b->nodes != NULL)
	{
		apply_instructions(&stack_a->nodes, &stack_b->nodes, PA);
		enqueue(instr_queue, PA);
		//		display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
	}
	//	display_qu(instr_queue, " all in a instructions");
}

void sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
				  t_node **instr_queue)
{
	int i;
	t_node *temp;

	i = 1;
	stack_a->size = find_len_stack(stack_a->nodes);
	temp = stack_a->nodes;
	while (temp->data < temp->prev->data)
	{
		i++;
		temp = temp->prev;
	}
	reset_moves(moves);
	if (i < stack_a->size / 2)
	{
		add_moves(*moves, RA, i);
		apply_moves(*moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
	}
	else if (i < stack_a->size)
	{
		add_moves(*moves, RRA, stack_a->size - i);
		apply_moves(*moves, &stack_a->nodes, &stack_b->nodes, instr_queue);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_node	*instr_queue;
	t_moves *moves;

	reset_input_push_swap(&stack_a, &stack_b, &instr_queue);
	if (argc == 1)
		return (0);
	build_input_push_swap(argc - 1, argv, &stack_a);
	if (sorted(stack_a.nodes))
		exit(0);

	//poner condicion si size <= 3 || size <= 5
	//	crear funcion para simplificar las 3 de abajo
	sort_stack_b(&stack_a, &stack_b, &moves, &instr_queue);
	pass_to_stack_a(&stack_a, &stack_b, &moves, &instr_queue);
	sort_stack_a(&stack_a, &stack_b, &moves, &instr_queue);
	print_queue(instr_queue);
	return (0);
}


// PARA TRES Y CINCO

//void sort_three(t_stack *stack_a, t_stack *stack_b, t_node *sorted_stack,
//				t_node **instr_queue)
//{
//	int	inst;
//
//	while (sorted_stack != NULL)
//	{
//		if (stack_a->nodes->next->data == stack_a->nodes->prev->prev->data &&
//			((stack_a->nodes->data > stack_a->nodes->prev->data && stack_a->nodes->data > stack_a->nodes->next->data) ||
//			 (stack_a->nodes->data < stack_a->nodes->prev->data && stack_a->nodes->data < stack_a->nodes->next->data)) &&
//			stack_a->nodes->prev->data > stack_a->nodes->next->data && check_swap_b(stack_a, stack_b))
//			inst = SS;
//		else if (stack_a->nodes->next->data == stack_a->nodes->prev->prev->data &&
//				 ((stack_a->nodes->data > stack_a->nodes->prev->data && stack_a->nodes->data > stack_a->nodes->next->data) ||
//				  (stack_a->nodes->data < stack_a->nodes->prev->data && stack_a->nodes->data < stack_a->nodes->next->data)) &&
//				 stack_a->nodes->prev->data > stack_a->nodes->next->data)
//			inst = SA;
//		else if (stack_a->nodes->next->data == stack_a->nodes->prev->prev->data &&
//				 stack_a->nodes->data > stack_a->nodes->prev->data &&
//				 stack_a->nodes->data < stack_a->nodes->next->data)
//		{
//			inst = SA;
//			if (stack_a->nodes->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->nodes->next->data == stack_a->nodes->prev->prev->data &&
//				 stack_a->nodes->data > stack_a->nodes->prev->data &&
//				 stack_a->nodes->data > stack_a->nodes->next->data)
//		{
//			inst = RA;
//			if (stack_a->nodes->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->nodes->next->data == stack_a->nodes->prev->prev->data &&
//				 stack_a->nodes->data < stack_a->nodes->prev->data &&
//				 stack_a->nodes->data > stack_a->nodes->next->data)
//		{
//			inst = RRA;
//			if (stack_a->nodes->next->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//			if (stack_a->nodes->prev->data == sorted_stack->data)
//				pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->nodes->data == sorted_stack->data)
//		{
//			inst = RA;
//			pop_sorted_stack(&sorted_stack);
//		}
//		else if (stack_a->nodes->next->data == sorted_stack->data)
//		{
//			pop_sorted_stack(&sorted_stack);
//			continue ;
//		}
//		else if (check_swap_a(stack_a, sorted_stack) && check_swap_b(stack_a, stack_b))
//			inst = SS;
//		else if (check_swap_a(stack_a, sorted_stack))
//			inst = SA;
//		else if (stack_a->nodes->prev->data < stack_a->nodes->next->data &&
//				 stack_a->nodes->data < stack_a->nodes->next->data &&
//				 stack_a->nodes->next->data > sorted_stack->data &&
//				 stack_a->nodes->prev->data > sorted_stack->data)
//			inst = RRA;
//		else if (stack_b != NULL && stack_b->nodes->data == sorted_stack->data)
//			inst = PA;
//		else if (stack_b == NULL || stack_b->nodes->data == stack_b->nodes->prev->data)
//			inst = PB;
//		else if (stack_a->nodes->data < sorted_stack->data &&
//				 stack_b->nodes->data > stack_b->nodes->prev->data)
//			inst = RB;
//		else if (check_swap_b(stack_a, stack_b))
//			inst = SB;
//		else
//			inst = next_move(stack_a,stack_b,sorted_stack); //esta funcion ya no existe
//		apply_instructions(&stack_a, &stack_b, inst);
//		enqueue(instr_queue, inst);
////		display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
//		i++;  // remove, it is just for testing
//	}
//}




// backup

//int	main(int argc, char **argv)
//{
//	t_stack	stack_a;
//	t_stack	stack_b;
//	t_node	*sorted_stack;
//	t_node	*instr_queue;
//	t_moves *moves;
//
//	reset_input_push_swap(&stack_a, &stack_b, &sorted_stack, &instr_queue);
//	if (argc == 1)
//		return (0);
//	build_input(argc - 1, argv, &stack_a.nodes, &sorted_stack);
//	if (sorted(stack_a.nodes))
//		exit(0);
//	sorted_stack = merge_sort(sorted_stack);
//	stack_a.size = find_len_stack(stack_a.nodes);
//
//	sort_stack_b(&stack_a, &stack_b, &moves, &instr_queue);
//	// PRIMERA FUNCION
//	while (stack_a.nodes != stack_a.nodes->next)
//	{
//		moves = check_head_a(stack_a.nodes, &stack_b);
//		if (moves->total == 0)
//		{
////			display_moves(moves);
//			apply_instructions(&stack_a.nodes, &stack_b.nodes, PB);
////			display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
//			enqueue(&instr_queue, PB);
//			stack_a.size--;
//			stack_b.size++;
//		}
//		else
//		{
//			check_moves_a(&stack_a, &stack_b, &moves);
////			display_moves(moves);
//			apply_moves(moves, &stack_a.nodes, &stack_b.nodes, &instr_queue);
//		}
//	}
//
//	// SEGUNDA FUNCION
//	moves = check_head_a(stack_a.nodes, &stack_b);
//	if (moves->total > 0)
//	{
//		apply_moves(moves, &stack_a.nodes, &stack_b.nodes, &instr_queue);
////		display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
//	}
//	while (stack_b.nodes != NULL)
//	{
//		apply_instructions(&stack_a.nodes, &stack_b.nodes, PA);
//		enqueue(&instr_queue, PA);
////		display_step(stack_a.nodes, stack_b.nodes	, sorted_stack, 0, PB);
//	}
////	display_qu(instr_queue, " all in a instructions");
//
//
//	// TERCERA FUNCION
//
//	stack_a.size = find_len_stack(stack_a.nodes);
//	int i = 1;
//	t_node *temp;
//	temp = stack_a.nodes;
//	while (temp->data < temp->prev->data)
//	{
//		i++;
//		temp = temp->prev;
//	}
//	reset_moves(&moves);
//	if (i < stack_a.size / 2)
//	{
//		add_moves(moves, RA, i);
//		apply_moves(moves, &stack_a.nodes, &stack_b.nodes, &instr_queue);
//	}
//	else if (i < stack_a.size)
//	{
//		add_moves(moves, RRA, stack_a.size - i);
//		apply_moves(moves, &stack_a.nodes, &stack_b.nodes, &instr_queue);
//	}
////	display_step(stack_a.nodes, stack_b.nodes, sorted_stack, 0, PB);
////	display_qu(instr_queue, " all in a instructions");
////	i = find_len_stack(instr_queue);
////	printf("queue %d\n", i);
//	print_queue(instr_queue);
//	return (0);
//}
