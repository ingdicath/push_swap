#include "push_swap.h"

// tail is included to disconnect from a circular double linked list
void	build_input(int size, char **argv, t_node **a, t_node **sorted)
{
	int		i;
	long	data;
	t_node	*tail;

	i = size;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]))
			break ;
		data = ft_atol(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			break ;
		push(a, (int)data);
		push(sorted, (int)data);
		i--;
	}
	if (i > 0)
		error_exit();
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}
