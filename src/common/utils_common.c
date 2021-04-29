/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

int	find_len_stack(t_node *head)
{
	int		len;
	t_node	*stack;
	t_node	*end;

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

void	display_step(t_stack stack_a, t_stack stack_b, int count, int inst)
{
	int	i;

	i = stack_a.size;
	if (i< stack_b.size)
		i = stack_b.size;
	ft_putstr_fd("-------------------------\n", STDOUT_FILENO);
	while (i > 0)
	{
		ft_putstr_fd("|", STDOUT_FILENO);
		print_step(&stack_a, i);
		print_step(&stack_b, i);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i--;
	}
	print_footer(inst, count);
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

void	display_moves(t_moves *moves)
{
	t_map *temp;

	dprintf(0, "total: %d | ", moves->total);
	temp = moves->inst;
	while (temp != NULL)
	{
		dprintf(0, "key: ");
		print_instructions(temp->key);

		dprintf(0, " value: %d -> |", temp->value);
		temp = temp->next;
	}
	dprintf(0, "\n");
}

void	print_center_num(int num)
{
	int len;
	int dif;
	int split;
	int i;

	len = ft_numlen(num);
	dif = 11 - len;
	split = dif / 2;
	i = 0;
	while (i < split)
	{
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	ft_putnbr_fd(num, STDOUT_FILENO);
	i = 0;
	while (i < (dif - split))
	{
		ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("|", STDOUT_FILENO);
}

void	print_footer(int inst, int count)
{
	ft_putstr_fd("| --------- | --------- |\n", STDOUT_FILENO);
	ft_putstr_fd("|  stack A  |  stack B  |\n", STDOUT_FILENO);
	print_instructions(inst);
	ft_putstr_fd(",\tstep ", STDOUT_FILENO);
	ft_putnbr_fd(count, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	print_step(t_stack *stack, int i)
{
	if (stack->size == i)
	{
		print_center_num(stack->nodes->data);
		stack->nodes = stack->nodes->prev;
		stack->size--;
	}
	else
		ft_putstr_fd("     -     |", STDOUT_FILENO);
}
