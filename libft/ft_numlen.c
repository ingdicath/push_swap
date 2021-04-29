//
// Created by diani on 4/28/2021.
//

#include "libft.h"

int	ft_numlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n <= -10 || n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}
