/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 21:55:17 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/03/13 21:55:47 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ------------------------------ Libraries -----------------------------------
*/

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h> //borrar

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef enum e_inst
{
	SA = 1, SB = 2, SS = 3, PA = 4, PB = 5, RA = 6, RB = 7, RR = 8, RRA = 9,
	RRB = 10, RRR = 11, ND = 12
} s_inst;

/*
** ------------------------------ checher -----------------------------------
*/

t_node *create_element(int data);
void push(t_node **head, int data);
int *pop(t_node **head);
void enqueue(t_node **head, int data);
int *peek(t_node *head);
int *deque(t_node **head);
void swap(t_node **head);
void swap_multiple(t_node **head_a, t_node **head_b);
void push_to_stack(t_node **from, t_node **to);
void rotate(t_node **head);
void rotate_multiple(t_node **head_a, t_node **head_b);
void reverse(t_node **head);
void reverse_multiple(t_node **head_a, t_node **head_b);
void error_exit(void);
void clean_stack(t_node **stack);
void build_input(int size, char **argv, t_node **a, t_node **sorted);
t_node *merge(t_node *first, t_node *second);
t_node *split_merge_sort(t_node *head);
t_node *merge_sort(t_node *head);
int read_instruction(char *input);
t_node *get_instructions(void);
void	apply_instructions(t_node **stack_a, t_node **stack_b, int instr);
int check_sort(t_node *stack_a, t_node *stack_b, t_node *sorted);


void display(t_node *head, char * name); //funcion de prueba
void display_qu(t_node *head, char *name) //funcion de prueba

#endif