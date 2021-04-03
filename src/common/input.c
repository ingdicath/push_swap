/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

// static void print_array(char **array) //borrar despues
// {
// 	int i;
// 	i = 0;
//
// 	while (array[i] != NULL)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// }

void	fill_initial_stack(int i, char **str, t_node **a, t_node **sorted)
{
	long	data;

//	 printf("i, %d str %s\n", i, str[i]);
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
	// printf("size is: %d i %d\n", size, i);
	// print_array(str);
	while (i > 0)
	{
		str = ft_split(argv[i], ' ');
		j = ft_array_size(str)-1;
//		 printf("size is: %d i %d j %d\n", size, i, j);
//		 print_array(str);
		while (j >= 0)
		{
			fill_initial_stack(j, str, a, sorted);
//			printf("size is: %d i %d j %d\n", size, i, j);
			j--;
		}
		ft_free_array(str);
		i--;
	}
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}
