/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

t_node	*sort_checker(t_node **stack_a, t_node **stack_b)
{
	int		*inst;
	t_node	*instr_queue;

	instr_queue = get_instructions();
//	int i=1; //borrar
	while (peek(instr_queue))
	{
		inst = deque(&instr_queue);
		apply_instructions(stack_a, stack_b, *inst);
//		display_step(*stack_a, *stack_b, NULL, i++, *inst); //funcion prueba
		free(inst);
	}
	return (instr_queue);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*sorted_stack;

	reset_input(&stack_a, &stack_b, &sorted_stack);
	if (argc == 1)
		return (0);
	build_input(argc - 1, argv, &stack_a, &sorted_stack);
	sorted_stack = merge_sort(sorted_stack);
	sort_checker(&stack_a, &stack_b);
	if (check_sort(stack_a, stack_b, sorted_stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (0);
}
