/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

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

void	clean_stack(t_node **stack)
{
	if (*stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

void	reset_input_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->nodes = NULL;
	stack_b->nodes = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
}

void	reset_moves(t_moves **moves)
{
	*moves = (t_moves *)malloc(sizeof(t_moves));
	(*moves)->total = 0;
	(*moves)->inst = NULL;
}

//void reset_map(t_map **new_element) //revisar si es necesario poner
//{
//	*new_element = (t_map *)malloc(sizeof(t_map));
//	(*new_element)->key = 0;
//	(*new_element)->value = 0;
//	(*new_element)->next = NULL;
//}
