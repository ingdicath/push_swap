/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

void	fill_initial_stack(int i, char **str, t_node **a, t_node **sorted)
{
	long	data;

	if (!ft_isnumber(str[i]))
		error_exit();
	data = ft_atol(str[i]);
	if (data > INT_MAX || data < INT_MIN)
		error_exit();
	push(a, (int)data);
	push(sorted, (int)data);
}

//  Tail is included to disconnect sorted from a circular doubly-linked list

void	build_input(int size, char **argv, t_node **a, t_node **sorted)
{
	int		i;
	int		j;
	t_node	*tail;
	char	**str;

	i = size;
	while (i > 0)
	{
		str = ft_split(argv[i], ' ');
		j = ft_array_size(str)-1;
		while (j >= 0)
		{
			fill_initial_stack(j, str, a, sorted);
			j--;
		}
		ft_free_array(str);
		i--;
	}
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}

// exclusivo para push swap

void	fill_initial_stack_push_swap(int i, char **str, t_node **a)
{
	long	data;

	if (!ft_isnumber(str[i]))
		error_exit();
	data = ft_atol(str[i]);
	if (data > INT_MAX || data < INT_MIN)
		error_exit();
	push(a, (int)data);
}

// exclusivo para push swap

void	build_input_push_swap(int size, char **argv, t_stack *stack_a)
{
	int		i;
	int		j;
	char	**str;

	i = size;
	while (i > 0)
	{
		str = ft_split(argv[i], ' ');
		j = ft_array_size(str)-1;
		while (j >= 0)
		{
			fill_initial_stack_push_swap(j, str, a);
			j--;
		}
		ft_free_array(str);
		i--;
	}
}

