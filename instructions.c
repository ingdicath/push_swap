/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:08:03 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:08:03 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
		return (RA);
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
