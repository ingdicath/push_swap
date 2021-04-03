/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	node_size(t_node *head)
{
	int		i;
	t_node	*temp;
	t_node	*tail;

	i = 0;
	temp = head;
	if (head == NULL)
		return (i);
	else
	{
		if (head->next != NULL)
			tail = head->next;
		while (temp != NULL && temp != tail)
		{
			temp = temp->prev;
			i++;
		}
		if (temp != NULL)
			i++;
	}
	return (i);
}

void	display_step(t_node *stack_a, t_node *stack_b, t_node *sorted_stack,
					 int count, int inst) //funcion de prueba
{
	int	size_a;
	int	size_b;
	int	size_sorted;
	int	i;

	size_a = node_size(stack_a);
	size_b = node_size(stack_b);
	size_sorted = node_size(sorted_stack);
	if (size_a >= size_b && size_a >= size_sorted)
		i = size_a;
	else if (size_b >= size_a && size_b >= size_sorted)
		i = size_b;
	else
		i = size_sorted;
	printf("---- Step %d------\n", count);
	while (i > 0)
	{
		printf("|");
		if (size_a == i)
		{
			printf(" %d |", stack_a->data);
			stack_a = stack_a->prev;
			size_a--;
		}
		else
			printf(" - |");
		if (size_b == i)
		{
			printf(" %d |", stack_b->data);
			stack_b = stack_b->prev;
			size_b--;
		}
		else
			printf(" - |");
		if (size_sorted == i)
		{
			printf(" %d |", sorted_stack->data);
			if (sorted_stack->prev != NULL)
				sorted_stack = sorted_stack->prev;
			size_sorted--;
		}
		else
			printf(" - |");
		printf("\n");
		i--;
	}
	printf("----------------- %d\n", inst);
}

void	display(t_node *head, char *name) //funcion de prueba
{
	t_node	*temp;
	t_node	*tail;

	temp = head;
	if (head == NULL)
		printf("Empty stack\n");
	else
	{
		if (head->next != NULL)
			tail = head->next;
		while (temp != NULL && temp != tail)
		{
			printf("%d\n", temp->data);
			temp = temp->prev;
		}
		if (temp != NULL)
			printf("%d\n", temp->data);
	}
	printf("---- %s \n", name);
}

void	display_qu(t_node *head, char *name) //funcion de prueba
{
	t_node	*temp;
	t_node	*tail;

	temp = head;
	if (head == NULL)
		printf("Empty queue\n");
	else
	{
		if (head->prev != NULL)
			tail = head->prev;
		while (temp != NULL && temp != tail)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
		if (temp != NULL)
			printf("%d\n", temp->data);
	}
	printf("---- %s \n", name);
}
