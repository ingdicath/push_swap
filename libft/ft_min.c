/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/20 13:37:39 by dsalaman      #+#    #+#                 */
/*   Updated: 2020/08/20 16:47:06 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	else
		return (num1);
}
