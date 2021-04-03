/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 09:51:57 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/15 09:51:57 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sort_checker(t_node **stack_a, t_node **stack_b)
{
	int		*inst;
	t_node	*instr_queue;

	instr_queue = get_instructions();
	while (peek(instr_queue))
	{
		printf("instruction %d\n", *peek(instr_queue));
		inst = deque(&instr_queue);
		apply_instructions(stack_a, stack_b, *inst);
		display(*stack_a, "stack a -- middle");
		display(*stack_b, "stack b -- middle");
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
	display(stack_a, "init stack a");
	display(sorted_stack, "sorted");
	sort_checker(&stack_a, &stack_b);
	if (check_sort(stack_a, stack_b, sorted_stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	// display(stack_a, "stack a");
	// display(stack_b, "stack b");
	return (0);
}
