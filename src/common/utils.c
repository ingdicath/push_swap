/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 08:09:22 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/29 08:09:22 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1); //revisar este codigo de error, 0? -1?
}

void	clean_stack(t_node **stack)
{
	if (*stack != NULL)
	{
		free(*stack);
		*stack = NULL;
	}
}

void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*sorted = NULL;
}
