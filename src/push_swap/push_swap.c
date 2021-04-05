/*
** Created by dsalaman on 2021/04/03
*/

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
		return (1);else if (stack_a->data <  stack_b->data &&
			stack_b->data >  stack_b->prev->data &&
			stack_a->data <  stack_b->next->data)
		return (1);
	return (0);
}

void testFuera(t_node **stack_a, t_node **stack_b,
			   t_node **sorted_stack, t_node **instr_queue, int *i)
{
	int inst;
	int count_ra;
	int count_rra;
	t_node *current;
	count_ra = 0;
	count_rra = 0;
	inst = PA;
	apply_instructions(stack_a, stack_b, inst);
	enqueue(instr_queue, inst);
//	display_step((*stack_a), (*stack_b), (*sorted_stack), (*i), inst); //funcion prueba
	(*i)++;  // remove, it is just for testing
	current = (*stack_a);
	while (current)
	{
		if ((*sorted_stack) != NULL && current->data == (*sorted_stack)->data)
		{
			pop_sorted_stack(sorted_stack);
			count_ra++;
		}
		else
			count_rra++;

		if (current == (*stack_a)->next)
			break ;
		current = current->prev;
	}
	if (count_ra < count_rra)
	{
		while (count_ra > 0)
		{
			inst = RA;
			apply_instructions(stack_a, stack_b, inst);
			enqueue(instr_queue, inst);
//			display_step((*stack_a), (*stack_b), (*sorted_stack), (*i), inst); //funcion prueba
			count_ra--;
			(*i)++;  // remove, it is just for testing
		}
	}
	else
	{
		while (count_rra > 0)
		{
			inst = RRA;
			apply_instructions(stack_a, stack_b, inst);
			enqueue(instr_queue, inst);
//			display_step((*stack_a), (*stack_b), (*sorted_stack), (*i), inst); //funcion prueba
			count_rra--;
			(*i)++;  // remove, it is just for testing
		}
	}
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
	build_input(argc - 1, argv, &stack_a, &sorted_stack);
	if (sorted(stack_a))
		exit(0);
	sorted_stack = merge_sort(sorted_stack);

	int finished;
	finished = 0;
//	int len;
//	len = find_len_stack(&stack_a);
//	printf("len: %d\n", len);

//	display_step(stack_a, stack_b, sorted_stack,1, 1);
	int i = 1;

//	display_step(stack_a, stack_b, sorted_stack, i-1, 0); //funcion prueba
	while (sorted_stack != NULL && !finished)
	{
		if (stack_a->next->data == stack_a->prev->prev->data &&
			((stack_a->data > stack_a->prev->data && stack_a->data > stack_a->next->data) ||
			 (stack_a->data < stack_a->prev->data && stack_a->data < stack_a->next->data)) &&
			stack_a->prev->data > stack_a->next->data && check_swap_b(stack_a, stack_b) &&
			stack_b == NULL)
			inst = SS;
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				 ((stack_a->data > stack_a->prev->data && stack_a->data > stack_a->next->data) ||
				  (stack_a->data < stack_a->prev->data && stack_a->data < stack_a->next->data)) &&
				 stack_a->prev->data > stack_a->next->data
				 && stack_b == NULL)
			inst = SA;
		else if (stack_a->next->data == stack_a->prev->prev->data &&
				stack_a->data > stack_a->prev->data &&
				stack_a->data < stack_a->next->data &&
				stack_b == NULL)
		{
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
				stack_a->data > stack_a->next->data &&
				stack_b == NULL)
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
				stack_a->data > stack_a->next->data &&
				stack_b == NULL)
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
		/**
		else if (check_swap_a(stack_a, sorted_stack) && check_swap_b(stack_a, stack_b))
			inst = SS;
		else if (check_swap_a(stack_a, sorted_stack))
		{
			inst = SA;
		}
		 */
//		else if (stack_b != NULL && stack_b->data == sorted_stack->data)
//			inst = PA;
		else if (stack_b == NULL || stack_b->data == stack_b->prev->data)
			inst = PB; // Solo un elemento
		else if (stack_a->data < sorted_stack->data )
		{
			finished = 1;
			continue ;
		}
//
//			&&
//				stack_b->data > stack_b->prev->data)
//			//funcion para decidir COMO MANDAR DE LA PILA b A LA A
//			inst = RB; //opcion de mejora, upgrade a  SB para SS o RR

//		else if (check_swap_b(stack_a, stack_b))
//			inst = SB; por ser swap b
		else
			inst = next_move(stack_a,stack_b,sorted_stack);
		apply_instructions(&stack_a, &stack_b, inst);
		enqueue(&instr_queue, inst);
//		display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
		i++;  // remove, it is just for testing
	}

	while (sorted_stack != NULL)
	{
		if (stack_b != NULL && stack_b->data > sorted_stack->data)
		{
			inst = PA;
			apply_instructions(&stack_a, &stack_b, inst);
			enqueue(&instr_queue, inst);
//			display_step(stack_a, stack_b, sorted_stack, i, inst); //funcion prueba
			i++;  // remove, it is just for testing
		}
		else if (stack_b->data == sorted_stack->data)
		{
			testFuera(&stack_a, &stack_b, &sorted_stack, &instr_queue, &i);
		}
	}

//	display_qu(instr_queue, "instructions");
//	display_step(stack_a, stack_b, sorted_stack, i, inst);
//	printf("Moves %d\n", i-1);
	i = find_len_stack(&instr_queue);
	printf("queue %d\n", i);
//	printf("Instruction is: %d", inst);

// PRINT INSTRUCTIONS
//	int *step;
//	while (peek(instr_queue))
//	{
//		step = deque(&instr_queue);
//		print_instructions(*step);
//		if (instr_queue != NULL)
//			ft_putstr("\n");
//		else
//			write(1, "\n", 1);
////		step = deque(&instr_queue);
//		free(step);
//	}
	return (0);
}
