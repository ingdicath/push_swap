/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:08:41 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:08:41 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*create_element(int data)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	new_element->data = data;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	push(t_node **head, int data)
{
	t_node	*new_element;
	t_node	*tail;

	new_element = create_element(data);
	if (*head == NULL)
	{
		*head = new_element;
		tail = new_element;
		tail->next = *head;
		tail->prev = *head;
	}
	else
	{
		tail = (*head)->next;
		(*head)->next = new_element;
		new_element->prev = *head;
		new_element->next = tail;
		tail->prev = new_element;
		*head = new_element;
	}
}

int	*pop(t_node **head)
{
	int		*data;
	t_node	*temp;
	t_node	*tail;

	temp = *head;
	if (*head == NULL)
		return (NULL);
	else if ((*head)->next == *head)
		*head = NULL;
	else
	{
		tail = (*head)->next;
		*head = (*head)->prev;
		(*head)->next = tail;
		tail->prev = *head;
	}
	data = (int *)malloc(sizeof(int));
	*data = temp->data;
	free(temp);
	return (data);
}
