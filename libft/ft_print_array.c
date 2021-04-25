/*
** Created by dsalaman on 2021/04/22
*/

#include "libft.h"

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		i++;
	}
	write(1, "\n", 1);
}
