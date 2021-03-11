#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ------------------------------ Libraries -----------------------------------
*/

# include <stdlib.h>
# include <stdio.h> //borrar
# include "libft/libft.h"

typedef struct s_stack
{
	int data;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

/*
** ------------------------------ checher -----------------------------------
*/

t_stack *create_element(int data);
void push(t_stack **head, int data);
int *pop(t_stack **head);
void display(t_stack *head, char * name); //funcion de prueba
void swap(t_stack **head);
void swap_multiple(t_stack **head_a, t_stack **head_b);
void push_to_stack(t_stack **from, t_stack **to);
void rotate(t_stack **head);
void rotate_multiple(t_stack **head_a, t_stack **head_b);
void reverse(t_stack **head);
void reverse_multiple(t_stack **head_a, t_stack **head_b);


int suma(int max); // funcion de ejemplo, borrar luego
int even_fibonacci(int max); // funcion de ejemplo, borrar luego

#endif