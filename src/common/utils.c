/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1); //revisar este codigo de error, 0? -1?
}

void	clean_stack(t_node **stack) //borrar luego si no se necesita
{
	if (*stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*sorted = NULL;
}

void	reset_input_push_swap(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue)
{
	stack_a->nodes = NULL;
	stack_b->nodes = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	*instr_queue = NULL;
}

void reset_moves(t_moves **moves)
{
	*moves = (t_moves *)malloc(sizeof(t_moves));
	(*moves)->total = 0;
	(*moves)->inst = NULL;
}

void reset_map(t_map **new_element) //revisar si es necesario poner
{
	*new_element = (t_map *)malloc(sizeof(t_map));
	(*new_element)->key = 0;
	(*new_element)->value = 0;
	(*new_element)->next = NULL;
}

