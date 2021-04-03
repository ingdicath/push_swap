/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

// Enqueue: adding an element to the rear of the queue.
// Dequeue: removing an element from the front of the queue.
// Peek: returns the value of the head node without dequeuing it.

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
	}
}

int	*peek(t_node *head)
{
	if (head == NULL)
		return (NULL);
	else
		return (&head->data);
}

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
