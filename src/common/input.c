/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

void	fill_stacks(char *str, t_node **a, t_node **sorted)
{
	int		data;
	size_t	count;

	count = ft_strlen(str);
	if (count > 11)
		error_exit();
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

int	build_input(int size, char **argv, t_node **a, t_node **sorted)
{
	int		i;
	int		j;
	int		flag;
	char	**str;

	flag = 0;
	i = size;
	if (ft_strcmp(argv[1], "-v") == 0)
		flag = 1;
	while (i > flag)
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
	unlink_circular_ref(sorted);
	return (flag);
}

void	unlink_circular_ref(t_node **node)
{
	t_node	*tail;

	if (*node != NULL)
	{
		tail = (*node)->next;
		(*node)->next = NULL;
		tail->prev = NULL;
	}
}
