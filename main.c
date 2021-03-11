#include "push_swap.h"

t_stack *create_element(int data)
{
	t_stack *new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	new_element->data = data;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void push(t_stack **head, int data)
{
	t_stack *new_element;
	t_stack *tail;

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

int *pop(t_stack **head)
{
	int *data;
	t_stack *temp;
	t_stack *tail;
	
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
	data = &temp->data;
	free(temp);
	return (data);
}

void display(t_stack *head) //funcion de prueba
{
	t_stack *temp;
	t_stack *tail;

	temp = head;
	if (head == NULL)
		printf("Empty stack\n");
	else
	{
		tail = head->next;

		while (temp != tail)
		{
			printf("%d\n", temp->data);
			temp = temp->prev;
		}
		printf("%d\n", temp->data);
	}
	printf("---- \n");
}

void swap(t_stack **head)
{
	int temp;

	temp = (*head)->data;
	(*head)->data = (*head)->prev->data;
	(*head)->prev->data = temp;
}

void swap_multiple(t_stack **head_a, t_stack **head_b)
{
	swap(head_a);
	swap(head_b);
}

void push_to_stack(t_stack **from, t_stack **to)
{
	int *data; 

	data = pop(from);
	if (data != NULL)
		push(to, *data);
}
// int main (int argc, char **argv)
int main (void)
{
	t_stack *temp = NULL;
	t_stack *otro = NULL;
	
	push(&temp, 2);
	
	display(temp);
	push(&temp, 2);
	display(temp);
	push(&temp, 16);
	display(temp);
	push(&temp, 4);
	display(temp);
	push(&temp, 3);
	display(temp);
	printf("starting pop\n");
	pop(&temp);
	display(temp);
	pop(&temp);
	display(temp);
	pop(&temp);
	display(temp);
	pop(&temp);
	display(temp);
	pop(&temp);
	display(temp);
	pop(&temp);
	display(temp);
	push(&temp, 3423);
	push(&temp, 312);
	push(&temp, 3);
	display(temp);
	pop(&temp);
	push(&temp, 0);
	display(temp);
	swap(&temp);
	display(temp);
	swap(&temp);
	display(temp);
	printf("push entre stacks\n");
	push_to_stack(&temp, &otro);
	display(temp);
	display(otro);
	push_to_stack(&otro, &temp);
	push_to_stack(&otro, &temp);
	push_to_stack(&otro, &temp);
	push_to_stack(&otro, &temp);
	push_to_stack(&otro, &temp);
	display(temp);
	display(otro);

// validacion de argumentos de entrada: numeros enteros, no duplicados, error si no hay entrada
	return (0);
}