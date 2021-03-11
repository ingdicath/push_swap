#include "push_swap.h"

// Data Structures: Linked List implementation of stacks
// t_stack *head; // es variable global, meterla luego como local
// head = NULL;

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

	new_element = create_element(data);
	if (*head == NULL)
	{
		*head = new_element;
		return ;
	}
	(*head)->prev = new_element;
	new_element->next = *head;
	*head = new_element;
}

int pop(t_stack **head)
{
	int data;
	t_stack *temp;

	if (*head == NULL)
		return ('0');
	temp = *head;

	data = temp->data;
	if (temp->next != NULL)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
	else
	{
		free(*head);
		*head = NULL;
	}
	return (data);
}

// void head()

// void is_empty_stack()

void print(t_stack *head)
{
	printf("stack: ");	
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}


// int main (int argc, char **argv)
int main (void)
{
	t_stack *temp;
	print(temp);
	push(&temp, 2);
	print(temp);
	push(&temp, 6);
	print(temp);
	push(&temp, 89);
	print(temp);
	pop(&temp);
	print(temp);
	pop(&temp);
	print(temp);
	pop(&temp);
	print(temp);
	pop(&temp);
	print(temp);

	// if (argc < 2)


// validacion de argumentos de entrada: numeros enteros, no duplicados, error si no hay entrada

	return (0);
}