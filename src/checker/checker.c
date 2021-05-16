/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		flag;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*sorted_stack;

	reset_input(&stack_a, &stack_b, &sorted_stack);
	if (argc == 1)
		return (0);
	flag = build_input(argc - 1, argv, &stack_a, &sorted_stack);
	sorted_stack = merge_sort(sorted_stack);
	sort_checker(&stack_a, &stack_b, flag);
	if (is_sorted(stack_a, stack_b, sorted_stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (0);
}
