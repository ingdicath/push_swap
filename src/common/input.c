/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

void	fill_stacks(char *str, t_node **a, t_node **sorted)
{
	int	data;

	data = map_data_to_int(str);
	push(a, data);
	push(sorted, data);
}

int	map_data_to_int(char *str)
{
	long	data;

	if (!ft_isnumber(str))
		error_exit();
	data = ft_atol(str);
	if (data > INT_MAX || data < INT_MIN)
		error_exit();
	return ((int)data);
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
		j = ft_array_size(str) - 1;
		while (j >= 0)
		{
			fill_stacks(str[j], a, sorted);
			j--;
		}
		ft_free_array(str);
		i--;
	}
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}
