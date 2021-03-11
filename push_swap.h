#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ------------------------------ Libraries -----------------------------------
*/

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int data;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;


int suma(int max); // funcion de ejemplo, borrar luego
int even_fibonacci(int max); // funcion de ejemplo, borrar luego

#endif