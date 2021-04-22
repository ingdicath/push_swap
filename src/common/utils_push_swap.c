/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	*pop_sorted_stack(t_node **head) //funcion antigua hasta 100 numbers
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

// Verifies if stack 'a' is already sorted

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

int	find_len_stack(t_node *head)
{
	t_node	*stack;
	t_node	*end;
	int		len;

	len = 0;
	stack = head;
	if (head)
		end = head->next;
	while (head)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->prev;
	}
	return (len);
}

// revisar si es necesario crear funcion para reset map
t_map	*create_map_element(int key, int value)
{
	t_map	*new_element;

	new_element = (t_map *)malloc(sizeof(t_map));
	if (!new_element)
		error_exit();
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}
