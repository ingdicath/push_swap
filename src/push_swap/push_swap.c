/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:40:06 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/04/01 19:22:15 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap_a(t_node *stack_a, t_node *sorted_stack)
{
	if (stack_a->prev->data == sorted_stack->data)
		return (1);
	return (0);
}

int	check_swap_b(t_node *stack_a, t_node *stack_b)
{
	if (stack_b == NULL || stack_b->prev->data !=  stack_b->next->data)
		return (0);
	else if (stack_a->data > stack_b->data &&
			stack_b->data > stack_b->prev->data &&
			stack_a->data >  stack_b->next->data)
		return (1);
	else if (stack_a->data >  stack_b->data &&
			stack_b->data <  stack_b->prev->data &&
			stack_a->data <  stack_b->next->data)
		return (1);
	else if (stack_a->data <  stack_b->data &&
			stack_b->data >  stack_b->prev->data &&
			stack_a->data <  stack_b->next->data)
		return (1);
	return (0);
}

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
			stack_a->prev->data > stack_a->next->data && check_swap_b(stack_a, stack_b))
			inst = SS;
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				 ((stack_a->data > stack_a->prev->data && stack_a->data > stack_a->next->data) ||
				  (stack_a->data < stack_a->prev->data && stack_a->data < stack_a->next->data)) &&
				 stack_a->prev->data > stack_a->next->data)
		{
//			printf("Ik ben een problem\n");
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
		else if (check_swap_a(stack_a, sorted_stack) && check_swap_b(stack_a, stack_b))
			inst = SS;
		else if (check_swap_a(stack_a, sorted_stack))
		{
//			printf("Edgaaaaar!\n");
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


		else if (check_swap_b(stack_a, stack_b))
			inst = SB;
		else
			inst = next_move(stack_a,stack_b,sorted_stack);

		apply_instructions(&stack_a, &stack_b, inst);
		enqueue(&instr_queue, inst);
//		display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
		i++;  // remove, it is just for testing
	}
//	display_qu(instr_queue, "instructions");
//	display_step(stack_a, stack_b, sorted_stack, i, inst);
//	printf("Moves %d\n", i-1);

//	printf("Instruction is: %d", inst);

// print instructions
	int *step;
	while (peek(instr_queue))
	{
		step = deque(&instr_queue);
		print_instructions(*step);
		if (instr_queue != NULL)
			ft_putstr("\n");
		else
			write(1, "\n", 1);
//		step = deque(&instr_queue);
		free(step);
//		pop de la cola
//		lo que salga del pop lo envio al print
	}
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
//			check_swap_b(stack_a, stack_b))
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
//		else if (check_swap_a(stack_a, sorted_stack) && check_swap_b(stack_a, stack_b))
//			inst = SS;
//		else if (check_swap_a(stack_a, sorted_stack))
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
//		else if (check_swap_b(stack_a, stack_b))
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