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

int	is_positionable(int current_a, int current_b, int next_b)
{
	if ((current_a > current_b && (current_b > next_b || current_a < next_b)) ||
		(next_b < current_b && current_a < current_b && current_a < next_b))
		return (1);
	return (0);
}

void	build_input_push_swap(int size, char **argv, t_stack *stack_a)
{
	t_node *sorted;

	sorted = NULL;
	build_input(size,argv,&stack_a->nodes,&sorted);
	stack_a->size = find_len_stack(stack_a->nodes);
	merge_sort(sorted);
	clean_stack(&sorted);
}
