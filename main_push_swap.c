/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 21:53:12 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/13 21:53:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pop2(t_node **head)
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


int node_size(t_node *head)
{
	int i;
	t_node *temp;
	t_node *tail;

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

void display_step(t_node *stack_a, t_node *stack_b, t_node *sorted_stack,
				  int count, int inst)
{
	int size_a;
	int size_b;
	int size_sorted;
	int i;

	i = 0;
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

void display(t_node *head, char *name) //funcion de prueba
{
	t_node *temp;
	t_node *tail;

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

void display_qu(t_node *head, char *name) //funcion de prueba
{
	t_node *temp;
	t_node *tail;

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

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;
	t_node *sorted_stack;
	t_node *instr_queue;
	 int inst;

	reset_input(&stack_a, &stack_b, &sorted_stack);
	if (argc == 1)
		return (0);
	build_input(argc - 1, argv, &stack_a, &sorted_stack);
	sorted_stack = merge_sort(sorted_stack);

//	display_step(stack_a, stack_b, sorted_stack,1, 1);

// selection sort stack A initial conditions, completar
	int i = 0;
	display_step(stack_a, stack_b, sorted_stack, i++, 0); //funcion prueba

	while (sorted_stack != NULL)
	{
		if (stack_a->data == sorted_stack->data)
		{
			inst = RA;
			apply_instructions(&stack_a, &stack_b, inst);
			pop2(&sorted_stack);
		}
		else if (stack_a->prev->data == sorted_stack->data)
		{
			inst = SA;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->next->data == sorted_stack->data)
		{
			pop2(&sorted_stack);
			continue ;
		}
		else if (stack_b != NULL && stack_b->data == sorted_stack->data)
		{
			inst = PA;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data < sorted_stack->data &&
				 stack_b->data > stack_b->prev->data)
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b == NULL || stack_b->data == stack_b->prev->data)
		{
			inst = PB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data < stack_b->data &&
				 stack_b->data > stack_b->next->data &&
				 stack_b->data > stack_b->prev->data
				 && stack_a->data < stack_b->prev->data
				 && stack_b->prev->data != stack_b->next->data
				 )
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data < stack_b->data &&
				 stack_b->data > stack_b->next->data &&
				 stack_b->data > stack_b->prev->data
				 && stack_a->data > stack_b->prev->data
				 && stack_a->data < stack_b->next->data
				 && stack_b->prev->data != stack_b->next->data)
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data > stack_b->data &&
				stack_b->data > stack_b->prev->data &&
				stack_b->data > stack_b->next->data &&
				stack_b->prev->data != stack_b->next->data)
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data > stack_b->data &&
				 stack_b->data < stack_b->prev->data &&
				 stack_b->data > stack_b->next->data &&
				 stack_b->prev->data != stack_b->next->data)
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data < stack_b->data &&
				 stack_b->data < stack_b->prev->data &&
				 stack_b->data > stack_b->next->data
				 && stack_a->data < stack_b->next->data
				&& stack_b->prev->data != stack_b->next->data)
		{
			inst = RRB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data > stack_b->data &&
				 stack_b->data < stack_b->prev->data &&
				 stack_b->data < stack_b->next->data &&
				stack_a->data < stack_b->next->data &&
				stack_b->prev->data != stack_b->next->data)
		{
			inst = RB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b->prev->data == stack_b->next->data &&
				stack_a->data > stack_b->data &&
				stack_b->data > stack_b->prev->data
				&& stack_a->data > stack_b->next->data)
		{
			inst = SB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b->prev->data == stack_b->next->data &&
				 stack_a->data > stack_b->data &&
				 stack_b->data < stack_b->prev->data
				 && stack_a->data < stack_b->next->data)
		{
			inst = SB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b->prev->data == stack_b->next->data &&
				 stack_a->data < stack_b->data &&
				 stack_b->data > stack_b->prev->data
				 && stack_a->data < stack_b->next->data)
		{
			inst = SB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else
		{
			inst = PB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		enqueue(&instr_queue, inst);
		display_step(stack_a, stack_b, sorted_stack, i++, inst); //funcion prueba
	}
	return (0);
}
