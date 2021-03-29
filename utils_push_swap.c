/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_push_swap.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:32:00 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:32:00 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pop_sorted_stack(t_node **head)
{
	int		*data;
	t_node	*temp;

	temp = *head;
	if (*head == NULL)
		return (NULL);
	else if ((*head)->prev == NULL)
		*head = NULL;
	else
		*head = (*head)->prev;
	data = (int *)malloc(sizeof(int));
	*data = temp->data;
	free(temp);
	return (data);
}

// Verify stack a is sorted, before starting
int	sorted(t_node *stack_a)
{
	t_node	*temp;

	if (!stack_a)
		return (0);
	temp = stack_a;
	while (temp->prev != stack_a)
	{
		if (temp->data > temp->prev->data)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	find_len_stack(t_node **head)
{
	t_node	*stack;
	t_node	*end;
	int		len;

	len = 0;
	stack = *head;
	if (*head)
		end = (*head)->next;
	while (*head)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->prev;
	}
	return (len);
}
