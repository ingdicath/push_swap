/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_push_moves.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:09:14 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:09:14 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_node **head)
{
	int	temp;

	if (*head == NULL)
		return ;
	temp = (*head)->data;
	(*head)->data = (*head)->prev->data;
	(*head)->prev->data = temp;
}

void	swap_multiple(t_node **head_a, t_node **head_b)
{
	swap(head_a);
	swap(head_b);
}

void	push_to_stack(t_node **from, t_node **to)
{
	int	*data;

	data = pop(from);
	if (data != NULL)
		push(to, *data);
	free(data);
}
