/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:08:54 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:08:54 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// put on queue
void	enqueue(t_node **head, int data)
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
		tail = (*head)->prev;
		tail->next = new_element;
		new_element->prev = tail;
		new_element->next = *head;
		(*head)->prev = new_element;
		tail = new_element;
	}
}

// chismosear head node
int	*peek(t_node *head)
{
	if (head == NULL)
		return (NULL);
	else
		return (&head->data);
}

// remove from the queue
int	*deque(t_node **head)
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
		tail = (*head)->prev;
		*head = (*head)->next;
		(*head)->prev = tail;
		tail->next = *head;
	}
	data = (int *)malloc(sizeof(int));
	*data = temp->data;
	free(temp);
	return (data);
}
