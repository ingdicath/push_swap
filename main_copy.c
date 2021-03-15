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

// t_node *create_element(int data)
// {
// 	t_node *new_element;

// 	new_element = (t_node *)malloc(sizeof(t_node));
// 	new_element->data = data;
// 	new_element->prev = NULL;
// 	new_element->next = NULL;
// 	return (new_element);
// }

// void push(t_node **head, int data)
// {
// 	t_node *new_element;
// 	t_node *tail;

// 	new_element = create_element(data);
// 	if (*head == NULL)
// 	{
// 		*head = new_element;
// 		tail = new_element;
// 		tail->next = *head;
// 		tail->prev = *head;
// 	}
// 	else
// 	{
// 		tail = (*head)->next;
// 		(*head)->next = new_element;
// 		new_element->prev = *head;
// 		new_element->next = tail;
// 		tail->prev = new_element;
// 		*head = new_element;
// 	}
// }

// int *pop(t_node **head)
// {
// 	int *data;
// 	t_node *temp;
// 	t_node *tail;

// 	temp = *head;
// 	if (*head == NULL)
// 		return (NULL);
// 	else if ((*head)->next == *head)
// 		*head = NULL;
// 	else
// 	{
// 		tail = (*head)->next;
// 		*head = (*head)->prev;
// 		(*head)->next = tail;
// 		tail->prev = *head;
// 	}
// 	data = (int *)malloc(sizeof(int));
// 	*data = temp->data;
// 	free(temp);
// 	return (data);
// }

// // put on queue
// void enqueue(t_node **head, int data)
// {
// 	t_node *new_element;
// 	t_node *tail;

// 	new_element = create_element(data);
// 	if (*head == NULL)
// 	{
// 		*head = new_element;
// 		tail = new_element;
// 		tail->next = *head;
// 		tail->prev = *head;
// 	}
// 	else
// 	{
// 		tail = (*head)->prev;
// 		tail->next = new_element;
// 		new_element->prev = tail;
// 		new_element->next = *head;
// 		(*head)->prev = new_element;
// 		tail = new_element;
// 	}
// }
// // chismosear head node
// int *peek(t_node *head)
// {
// 	if (head == NULL)
// 		return (NULL);
// 	else
// 		return (&head->data);
// }

// // remove from the queue
// int *deque(t_node **head)
// {
// 	int *data;
// 	t_node *temp;
// 	t_node *tail;

// 	temp = *head;
// 	if (*head == NULL)
// 		return (NULL);
// 	else if ((*head)->next == *head)
// 		*head = NULL;
// 	else
// 	{
// 		tail = (*head)->prev;
// 		*head = (*head)->next;
// 		(*head)->prev = tail;
// 		tail->next = *head;
// 	}
// 	data = (int *)malloc(sizeof(int));
// 	*data = temp->data;
// 	free(temp);
// 	return (data);
// }


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

// void swap(t_node **head)
// {
// 	int temp;

// 	if (*head == NULL)
// 		return ;
// 	temp = (*head)->data;
// 	(*head)->data = (*head)->prev->data;
// 	(*head)->prev->data = temp;
// }

// void swap_multiple(t_node **head_a, t_node **head_b)
// {
// 	swap(head_a);
// 	swap(head_b);
// }

// void push_to_stack(t_node **from, t_node **to)
// {
// 	int *data;

// 	data = pop(from);
// 	if (data != NULL)
// 		push(to, *data);
// 	free(data);
// }

// void rotate(t_node **head)
// {
// 	if (*head != NULL)
// 		*head = (*head)->prev;
// }

// void rotate_multiple(t_node **head_a, t_node **head_b)
// {
// 	rotate(head_a);
// 	rotate(head_b);
// }

// void reverse(t_node **head)
// {
// 	if (*head != NULL)
// 		*head = (*head)->next;
// }

// void reverse_multiple(t_node **head_a, t_node **head_b)
// {
// 	reverse(head_a);
// 	reverse(head_b);
// }

// void error_exit(void)
// {
// 	ft_putendl_fd("Error", STDERR_FILENO);
// 	exit(1);
// }

// void clean_stack(t_node **stack)
// {
// 	if (*stack != NULL)
// 	{
// 		free(*stack);
// 		*stack = NULL;
// 	}
// }

// // tail is included to disconnect from a circular double linked list
// void build_input(int size, char **argv, t_node **a, t_node **sorted)
// {
// 	int i;
// 	long data;
// 	t_node *tail;

// 	i = size;
// 	while (i > 0)
// 	{
// 		if (!ft_isnumber(argv[i]))
// 			break;
// 		data = ft_atol(argv[i]);
// 		if (data > INT_MAX || data < INT_MIN)
// 			break;
// 		push(a, (int)data);
// 		push(sorted, (int)data);
// 		i--;
// 	}
// 	if (i > 0)
// 		error_exit();
// 	tail = (*sorted)->next;
// 	(*sorted)->next = NULL;
// 	tail->prev = NULL;
// }

// // Function to merge two linked lists
// t_node *merge(t_node *first, t_node *second)
// {
// 	if (!first)
// 		return (second);
// 	if (!second)
// 		return (first);
// 	if (first->data == second->data)
// 	{
// 		error_exit();
// 		return (NULL);
// 	}
// 	else if (first->data < second->data)
// 	{
// 		first->prev = merge(first->prev, second);
// 		first->prev->next = first;
// 		first->next = NULL;
// 		return (first);
// 	}
// 	else
// 	{
// 		second->prev = merge(first, second->prev);
// 		second->prev->next = second;
// 		second->next = NULL;
// 		return (second);
// 	}
// }

// // Split a doubly linked list (DLL) into 2 DLLs of half sizes
// // we use prev because we start in the top of the stack
// t_node *split_merge_sort(t_node *head)
// {
// 	t_node *fast;
// 	t_node *slow;
// 	t_node *temp;

// 	fast = head;
// 	slow = head;
// 	while (fast->prev && fast->prev->prev)
// 	{
// 		fast = fast->prev->prev;
// 		slow = slow->prev;
// 	}
// 	temp = slow->prev;
// 	slow->prev = NULL;
// 	return (temp);
// }

// // Function to do merge sort
// t_node *merge_sort(t_node *head)
// {
// 	t_node *second;
// 	second = NULL;

// 	if (!head || !head->prev)
// 		return (head);
// 	second = split_merge_sort(head);
// 	head = merge_sort(head);
// 	second = merge_sort(second);
// 	return (merge(head, second));
// }

// int read_instruction(char *input)
// {
// 	if (ft_strcmp("sa", input) == 0)
// 		return (SA);
// 	else if (ft_strcmp("sb", input) == 0)
// 		return (SB);
// 	else if (ft_strcmp("ss", input) == 0)
// 		return (SS);
// 	else if (ft_strcmp("pa", input) == 0)
// 		return (PA);
// 	else if (ft_strcmp("pb", input) == 0)
// 		return (PB);
// 	else if (ft_strcmp("ra", input) == 0)
// 		return (RA);
// 	else if (ft_strcmp("rb", input) == 0)
// 		return (RA);
// 	else if (ft_strcmp("rr", input) == 0)
// 		return (RR);
// 	else if (ft_strcmp("rra", input) == 0)
// 		return (RRA);
// 	else if (ft_strcmp("rrb", input) == 0)
// 		return (RRB);
// 	else if (ft_strcmp("rrr", input) == 0)
// 		return (RRR);
// 	else
// 		return (ND);
// }

// t_node *get_instructions(void)
// {
// 	int flag;
// 	char *line;
// 	t_node *inst_queue;

// 	flag = 1;
// 	inst_queue = NULL;
// 	while (flag > 0)
// 	{
// 		flag = get_next_line(STDIN_FILENO, &line);
// 		if (flag > 0)
// 			enqueue(&inst_queue, read_instruction(line));
// 		free(line);
// 		line = NULL;
// 	}
// 	return (inst_queue);
// }

// void	apply_instructions(t_node **stack_a, t_node **stack_b, int instr)
// {
// 	if (SA == instr)
// 		swap(stack_a);
// 	else if (SB == instr)
// 		swap(stack_b);
// 	else if (SS == instr)
// 		swap_multiple(stack_a, stack_b);
// 	else if (PA == instr)
// 		push_to_stack(stack_b, stack_a);
// 	else if (PB == instr)
// 		push_to_stack(stack_a, stack_b);
// 	else if (RA == instr)
// 		rotate(stack_a);
// 	else if (RB == instr)
// 		rotate(stack_b);
// 	else if (RR == instr)
// 		rotate_multiple(stack_a, stack_b);
// 	else if (RRA == instr)
// 		reverse(stack_a);
// 	else if (RRB == instr)
// 		reverse(stack_b);
// 	else if (RRR == instr)
// 		reverse_multiple(stack_a, stack_b);
// 	else
// 		error_exit();
// }

// int check_sort(t_node *stack_a, t_node *stack_b, t_node *sorted)
// {
// 	if (stack_b != NULL)
// 		return (0);
// 	while (sorted != NULL)
// 	{
// 		if (stack_a->data != sorted->data)
// 			return (0);
// 		stack_a = stack_a->prev;
// 		sorted = sorted->prev;
// 	}
// 	return (1);
// }

int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;
	t_node *sorted_stack;
	t_node *instr_queue;
	int *inst;

	reset_input(&stack_a, &stack_b, &sorted_stack);
	if (argc == 1)
		return (0);
	build_input(argc - 1, argv, &stack_a, &sorted_stack);
	sorted_stack = merge_sort(sorted_stack);
	display(stack_a, "init stack a");
	display(sorted_stack, "sorted");
	instr_queue = get_instructions(); // poner en otra funcion
	while (peek(instr_queue))// poner en otra funcion
	{
		printf("instruction %d\n", *peek(instr_queue));
		inst = deque(&instr_queue);
		apply_instructions(&stack_a, &stack_b, *inst);
		display(stack_a, "stack a -- middle");
		display(stack_b, "stack b -- middle");
		free(inst);
	}
	if (check_sort(stack_a, stack_b, sorted_stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	// display(stack_a, "stack a");
	// display(stack_b, "stack b");
	return (0);
}

// int main (void)
// {
// char *s = "123";
// int num = atoi(s);
// int cu = ft_isnumber(s);
// printf("El valor num es: %d\n", num);
// printf("El valor cu es: %d\n", cu);
// 	t_node *temp = NULL;
// 	t_node *otro = NULL;
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
