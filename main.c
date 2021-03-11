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

void display(t_stack *head, char * name) //funcion de prueba
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
	printf("---- %s \n", name);
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

void rotate(t_stack **head)
{
	if (*head != NULL)
		*head = (*head)->prev;
}

void rotate_multiple(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void reverse(t_stack **head)
{
	if (*head != NULL)
		*head = (*head)->next;
}

void reverse_multiple(t_stack **head_a, t_stack **head_b)
{
	reverse(head_a);
	reverse(head_b);
}

// validar duplicados
// validar sean numeros
// 

// validar numero por numero
// si es numero, lo meto al arreglo de positivo o negativo
// creo arreglo dinamico con malloc(tamano argc-1)
// si el numero no esta duplicado, lo mando al nuevo arreglo dinamico
// al final debo recorrer el arreglo de atras hacia adelante para meterlo en la pila

int main (int argc, char **argv)
{
	static int positives[2147483647] = {0};
	// int negatives[2147483648];

	printf("%d\n", positives[56]);

	
	if (argc == 1)
		return (0);

	
	return (0);
}



// int main (void)
// {
// 	t_stack *temp = NULL;
// 	t_stack *otro = NULL;
	
// 	push(&temp, 2);
	
// 	display(temp,"A");
// 	push(&temp, 2);
// 	display(temp, "A");
// 	push(&temp, 16);
// 	display(temp, "A");
// 	push(&temp, 4);
// 	display(temp, "A");
// 	push(&temp, 3);
// 	display(temp, "A");
// 	printf("starting pop\n");
// 	pop(&temp);
// 	display(temp, "A");
// 	pop(&temp);
// 	display(temp, "A");
// 	pop(&temp);
// 	display(temp, "A");
// 	pop(&temp);
// 	display(temp, "A");
// 	pop(&temp);
// 	display(temp, "A");
// 	pop(&temp);
// 	display(temp, "A");
// 	push(&temp, 3423);
// 	push(&temp, 312);
// 	push(&temp, 3);
// 	display(temp, "A");
// 	pop(&temp);
// 	push(&temp, 0);
// 	display(temp, "A");
// 	swap(&temp);
// 	display(temp, "A");
// 	swap(&temp);
// 	display(temp, "A");
// 	printf("push entre stacks\n");
// 	push_to_stack(&temp, &otro);
// 	display(temp, "A");
// 	display(otro, "B");
// 	// push_to_stack(&otro, &temp);
// 	// push_to_stack(&otro, &temp);
// 	// push_to_stack(&otro, &temp);
// 	// push_to_stack(&otro, &temp);
// 	// push_to_stack(&otro, &temp);
// 	display(temp, "A");
// 	display(otro, "B");
// 	push(&temp, 57);
// 	display(temp, "A");
// 	push(&temp, 78);
// 	display(temp, "A");
// 	printf("rotate\n");
// 	rotate(&temp);
// 	push(&otro, 8);
// 	push(&otro, 48);
// 	display(temp, "A");
// 	display(otro, "B");
// 	printf("rotate multiple\n");
// 	rotate_multiple(&temp,&otro);
// 	display(temp, "A");
// 	display(otro, "B");
// 	printf("reverse\n");
// 	reverse(&temp);
// 	reverse(&otro);
// 	display(temp, "A");
// 	display(otro, "B");
// 	printf("reverse multiple\n");
// 	reverse_multiple(&temp, &otro);
// 	display(temp, "A");
// 	display(otro, "B");
	
// // validacion de argumentos de entrada: numeros enteros, no duplicados, error si no hay entrada
// 	return (0);
// }