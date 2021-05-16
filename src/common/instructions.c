/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	read_instruction(char *input)
{
	if (ft_strcmp("sa", input) == 0)
		return (SA);
	else if (ft_strcmp("sb", input) == 0)
		return (SB);
	else if (ft_strcmp("ss", input) == 0)
		return (SS);
	else if (ft_strcmp("pa", input) == 0)
		return (PA);
	else if (ft_strcmp("pb", input) == 0)
		return (PB);
	else if (ft_strcmp("ra", input) == 0)
		return (RA);
	else if (ft_strcmp("rb", input) == 0)
		return (RB);
	else if (ft_strcmp("rr", input) == 0)
		return (RR);
	else if (ft_strcmp("rra", input) == 0)
		return (RRA);
	else if (ft_strcmp("rrb", input) == 0)
		return (RRB);
	else if (ft_strcmp("rrr", input) == 0)
		return (RRR);
	else
		return (ND);
}

t_node	*get_instructions(void)
{
	int		flag;
	char	*line;
	t_node	*inst_queue;

	flag = 1;
	inst_queue = NULL;
	while (flag > 0)
	{
		flag = get_next_line(STDIN_FILENO, &line);
		if (flag > 0)
			enqueue(&inst_queue, read_instruction(line));
		free(line);
		line = NULL;
	}
	return (inst_queue);
}

void	apply_instructions(t_node **stack_a, t_node **stack_b, int instr)
{
	if (SA == instr)
		swap(stack_a);
	else if (SB == instr)
		swap(stack_b);
	else if (SS == instr)
		swap_multiple(stack_a, stack_b);
	else if (PA == instr)
		push_to_stack(stack_b, stack_a);
	else if (PB == instr)
		push_to_stack(stack_a, stack_b);
	else if (RA == instr)
		rotate(stack_a);
	else if (RB == instr)
		rotate(stack_b);
	else if (RR == instr)
		rotate_multiple(stack_a, stack_b);
	else if (RRA == instr)
		reverse(stack_a);
	else if (RRB == instr)
		reverse(stack_b);
	else if (RRR == instr)
		reverse_multiple(stack_a, stack_b);
	else
		error_exit();
}

void	print_instructions(int instr)
{
	if (SA == instr)
		ft_putstr_fd("sa", STDOUT_FILENO);
	else if (SB == instr)
		ft_putstr_fd("sb", STDOUT_FILENO);
	else if (SS == instr)
		ft_putstr_fd("ss", STDOUT_FILENO);
	else if (PA == instr)
		ft_putstr_fd("pa", STDOUT_FILENO);
	else if (PB == instr)
		ft_putstr_fd("pb", STDOUT_FILENO);
	else if (RA == instr)
		ft_putstr_fd("ra", STDOUT_FILENO);
	else if (RB == instr)
		ft_putstr_fd("rb", STDOUT_FILENO);
	else if (RR == instr)
		ft_putstr_fd("rr", STDOUT_FILENO);
	else if (RRA == instr)
		ft_putstr_fd("rra", STDOUT_FILENO);
	else if (RRB == instr)
		ft_putstr_fd("rrb", STDOUT_FILENO);
	else if (RRR == instr)
		ft_putstr_fd("rrr", STDOUT_FILENO);
}

void	apply_push_instruction(t_stack *from, t_stack *to, int inst,
			t_node **instr_queue)
{
	push_to_stack(&from->nodes, &to->nodes);
	enqueue(instr_queue, inst);
	from->size--;
	to->size++;
}
