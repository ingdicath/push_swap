/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

t_node	*sort_checker(t_node **stack_a, t_node **stack_b, int flag)
{
	int		*inst;
	t_node	*instr_queue;
	int count;

	count = 0;
	instr_queue = get_instructions();
	while (peek(instr_queue))
	{
		inst = deque(&instr_queue);
		if (flag)
			print_debug_flag(*stack_a, *stack_b, count, *inst);
		apply_instructions(stack_a, stack_b, *inst);
		count++;
		free(inst);
	}
	if (flag)
		print_debug_flag(*stack_a, *stack_b, count, *inst);
	return (instr_queue);
}

int	is_sorted(t_node *stack_a, t_node *stack_b, t_node *sorted)
{
	if (stack_b != NULL)
		return (0);
	while (sorted != NULL)
	{
		if (stack_a->data != sorted->data)
			return (0);
		stack_a = stack_a->prev;
		sorted = sorted->prev;
	}
	return (1);
}

void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*sorted = NULL;
}

// double while replace function -> usleep(1000000);

void	print_debug_flag(t_node *node_a, t_node *node_b, int count, int inst)
{
	int		i;
	int		j;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	j = 0;
	stack_a.size = find_len_stack(node_a);
	stack_b.size = find_len_stack(node_b);
	stack_a.nodes = node_a;
	stack_b.nodes = node_b;
	ft_putstr_fd("\E[H\E[2J", STDOUT_FILENO);
	display_step(stack_a, stack_b, count, inst);
	while (i < FIRST_WHILE)
	{
		while (j < SECOND_WHILE)
			j++;
		i++;
	}
}