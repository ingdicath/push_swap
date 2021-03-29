/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: null <null@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 16:03:44 by null          #+#    #+#                 */
/*   Updated: 2021/03/18 16:03:44 by null          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//		{
//			// Se anade esta condicion para incluir RR instruction
//			if (stack_a->data < stack_b->data &&  //ver si esta cndicion es necesaria
//				stack_b->data != stack_b->prev->data &&
//				stack_b->data > stack_b->prev->data &&
//				stack_b->data > stack_b->next->data)
//				{
//					apply_instructions(&stack_a, &stack_b, RR);
//					enqueue(&instr_queue, RR);
//				}
//			apply_instructions(&stack_a, &stack_b, RA);
//			enqueue(&instr_queue, RA);
//			pop(&sorted_stack);
//		}
////		else if (stack_a->prev->data == sorted_stack->data)
////		{
////			apply_instructions(&stack_a, &stack_b, SA);
////			enqueue(&instr_queue, SA);
////		}
////		else if (stack_a->next->data == sorted_stack->data)
////		{
////			apply_instructions(&stack_a, &stack_b, RRA);
////			enqueue(&instr_queue, RRA);
////		}
//		else // como decirle que  ejecute este paso solo si stack b esta vacio
//		{
////			colocar al contrario las condiiones para no hacer tan largo el if
//
//			if (stack_b != NULL && stack_b->data != stack_b->prev->data) //add 18mar
//			{
//				// si el elemento que acaba de entrar a stack b es mayor al prev y al tail de pila b
//				//esto se puede factorizar, ver como
//				if (stack_a->data < stack_b->data &&
//					stack_b->data > stack_b->prev->data &&
//					stack_b->data > stack_b->next->data)
//				{
//					apply_instructions(&stack_a, &stack_b, PB);
//					enqueue(&instr_queue, PB);
//					apply_instructions(&stack_a, &stack_b, RB);
//					enqueue(&instr_queue, RB);
//				}
//				// caso 2, cuando head de stack 'a' coincide con el valor buscado en sorted stack
//				else if (stack_a->data == sorted_stack->data &&
//					stack_a->data < stack_b->data && //revisar si es necesaria esta condicion, tal vez quitar
//					stack_b->data > stack_b->prev->data &&
//					stack_b->data > stack_b->next->data)
//				{
//					apply_instructions(&stack_a, &stack_b, RB);
//					enqueue(&instr_queue, RB);
//				}
//				// cuando las dos pilas se encuentran ordenadas, hay que empezar a pasar de 'b' a 'a'
//				else if ( (stack_b->data == sorted_stack->data))
//				{
//					apply_instructions(&stack_a, &stack_b, PA);
//					enqueue(&instr_queue, PA);
//					apply_instructions(&stack_a, &stack_b, RA);
//					enqueue(&instr_queue, RA);
//				}
//			}
//			apply_instructions(&stack_a, &stack_b, PB);
//			enqueue(&instr_queue, PB);
//1) aplicar reglas de insertion sort en la pila B, completar validaciones
//2) movimientos multiples, establecer reglas
//		}


/*
 * 18 de marzo
 */

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

//	display(stack_a, "init stack a"); //test
//	display(sorted_stack, "sorted"); //test

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
//			inst = RRA;
//			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b != NULL && stack_b->data == sorted_stack->data)
		{
			inst = PA;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_b == NULL || stack_b->data == stack_b->prev->data)
		{
			inst = PB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data > stack_b->data &&
				stack_b->data > stack_b->prev->data &&
				stack_b->data > stack_b->next->data)
		{
			inst = SB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data > stack_b->data)
		{
			inst = PB;
			apply_instructions(&stack_a, &stack_b, inst);
		}
		else if (stack_a->data < stack_b->data && stack_b->data > stack_b->next->data)
		{
			inst = RB;
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
