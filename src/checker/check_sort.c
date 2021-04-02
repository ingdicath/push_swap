/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:06:45 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/04/01 19:15:04 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
