/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:07:09 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:07:09 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_array(char **array) //borrar despues
// {
// 	int i;
// 	i = 0;

// 	while (array[i] != NULL)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}

// }

void	fill_initial_stack(int i, char **str, t_node **a, t_node **sorted)
{
	long	data;

	// printf("i, %d str %s\n", i, str[i]);
	if (!ft_isnumber(str[i]))
		error_exit();
	data = ft_atol(str[i]);
	if (data > INT_MAX || data < INT_MIN)
		error_exit();
	push(a, (int)data);
	push(sorted, (int)data);
}

/*
**  Tail is included to disconnect sorted from a circular doubly-linked list
*/

void	build_input(int size, char **argv, t_node **a, t_node **sorted)
{
	int		i;
	t_node	*tail;
	char	**str;

	i = size;
	str = argv;
	if (size == 1)
	{
		str = ft_split(argv[1], ' ');
		i = ft_array_size(str);
	}		
	// printf("size is: %d i %d\n", size, i);
	// print_array(str);
	while (i > 0)
	{
		if (size == 1)
			fill_initial_stack(i - 1, str, a, sorted);
		else
			fill_initial_stack(i, str, a, sorted);
		i--;
	}
	if (size == 1)
		ft_free_array(str);
	tail = (*sorted)->next;
	(*sorted)->next = NULL;
	tail->prev = NULL;
}
