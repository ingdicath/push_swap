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

void display(t_stack *head, char *name) //funcion de prueba
{
	t_stack *temp;
	t_stack *tail;

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

// validar numero por numero ok
// si es numero, lo meto al arreglo de positivo o negativo
// creo arreglo dinamico con malloc(tamano argc-1)
// si el numero no esta duplicado, lo mando al nuevo arreglo dinamico
// al final debo recorrer el arreglo de atras hacia adelante para meterlo en la pila

// void print_int_array(int *input, int size) //funcion de prueba
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", input[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void error_exit(void)
{
	ft_putstr("Error\n");
	exit(1); //validar
}

void clean_stack(t_stack **stack)
{
	if (*stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

// tail is included to disconnect from a circular double linked list
void build_input(int size, char **argv, t_stack **a, t_stack **sorted)
{
	int i;
	long data;
	t_stack *tail;

	i = size;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]))
			break;
		data = ft_atol(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			break;
		push(a, (int)data);
		push(sorted, (int)data);
		i--;
	}
	if (i > 0)
	{
		// clean_stack(a);
		// clean_stack(sorted);
		error_exit();
	}
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}

// Function to merge two linked lists
t_stack *merge(t_stack *first, t_stack *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data == second->data)
	{
		error_exit();
		return (NULL);
	}
	else if (first->data < second->data)
	{
		first->prev = merge(first->prev, second);
		first->prev->next = first;
		first->next = NULL;
		return (first);
	}
	else
	{
		second->prev = merge(first, second->prev);
		second->prev->next = second;
		second->next = NULL;
		return (second);
	}
}

// Split a doubly linked list (DLL) into 2 DLLs of half sizes
// we use prev because we start in the top of the stack
t_stack *split_merge_sort(t_stack *head)
{
	t_stack *fast;
	t_stack *slow;
	t_stack *temp;

	fast = head;
	slow = head;
	while (fast->prev && fast->prev->prev)
	{
		fast = fast->prev->prev;
		slow = slow->prev;
	}
	temp = slow->prev;
	slow->prev = NULL;
	return (temp);
}

// Function to do merge sort
t_stack *merge_sort(t_stack *head)
{
	t_stack *second;
	second = NULL;

	if (!head || !head->prev)
		return (head);
	second = split_merge_sort(head);

	head = merge_sort(head);
	second = merge_sort(second);

	return (merge(head, second)); //not defined yet
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	// t_stack *stack_b;
	t_stack *sorted_stack;

	stack_a = NULL;
	// stack_b = NULL;
	sorted_stack = NULL;

	if (argc == 1)
		return (0);
	build_input(argc - 1, argv, &stack_a, &sorted_stack);
	sorted_stack = merge_sort(sorted_stack);

	display(stack_a, "stack a");
	display(sorted_stack, "sorted");
	return (0);
}

// int main (void)
// {
// char *s = "123";
// int num = atoi(s);
// int cu = ft_isnumber(s);
// printf("El valor num es: %d\n", num);
// printf("El valor cu es: %d\n", cu);
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
// 	return (0);
// }
