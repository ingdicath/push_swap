/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_reverse_moves.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:09:09 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:09:09 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_node **head)
{
	if (*head != NULL)
		*head = (*head)->prev;
}

void	rotate_multiple(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	reverse(t_node **head)
{
	if (*head != NULL)
		*head = (*head)->next;
}

void	reverse_multiple(t_node **head_a, t_node **head_b)
{
	reverse(head_a);
	reverse(head_b);
}
