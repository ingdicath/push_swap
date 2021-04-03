/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	check_sort(t_node *stack_a, t_node *stack_b, t_node *sorted)
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
