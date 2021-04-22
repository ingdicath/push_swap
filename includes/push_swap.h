/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsalaman <dsalaman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 21:55:17 by dsalaman      #+#    #+#                 */
/*   Updated: 2021/04/01 19:09:00 by dsalaman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ------------------------------ Libraries -----------------------------------

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h> //borrar

// ------------------ Doubly-linked list --------------------------------------

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_map
{
	int				key;
	int				value;
	struct s_map	*next;
}	t_map;

typedef struct s_moves
{
	int				total;
	t_map 			*inst;
}	t_moves;

typedef struct s_stack
{
	t_node		*nodes;
	int 		size;
}	t_stack;
// -------------------------- Movements ---------------------------------------

typedef enum e_inst
{
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11,
	ND = 12
}	t_inst;

// ------------------------------ common -----------------------------------

int		map_data_to_int(char *str);

// ------------------------------ checker -----------------------------------

t_node	*create_element(int data);
void	push(t_node **head, int data);
int		*pop(t_node **head);
void	enqueue(t_node **head, int data);
int		*peek(t_node *head);
int		*deque(t_node **head);
void	swap(t_node **head);
void	swap_multiple(t_node **head_a, t_node **head_b);
void	push_to_stack(t_node **from, t_node **to);
void	rotate(t_node **head);
void	rotate_multiple(t_node **head_a, t_node **head_b);
void	reverse(t_node **head);
void	reverse_multiple(t_node **head_a, t_node **head_b);
void	error_exit(void);
void	clean_stack(t_node **stack); //borrar
void	build_input(int size, char **argv, t_node **a, t_node **sorted);
t_node	*merge(t_node *first, t_node *second);
t_node	*split_merge_sort(t_node *head);
t_node	*merge_sort(t_node *head);
int		read_instruction(char *input);
t_node	*get_instructions(void);
void	apply_instructions(t_node **stack_a, t_node **stack_b, int instr);
int		check_sort(t_node *stack_a, t_node *stack_b, t_node *sorted);
void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted);
t_node	*sort_checker(t_node **stack_a, t_node **stack_b);
void	fill_stacks(char *str, t_node **a, t_node **sorted);

// ------------------------------ push_swap -----------------------------------

int		*pop_sorted_stack(t_node **head);
int		check_swap_a(t_stack *stack_a, t_node *sorted_stack);
int		check_swap_b(t_node *stack_a, t_node *stack_b);
int		sorted(t_node *stack_a);
int		find_len_stack(t_node *head);
void	print_instructions(int instr);
void	fill_push_swap_stack(char *str, t_node **a);
void	reset_input_push_swap(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue);
int		check_first_half_b(t_node *current_a, t_stack *stack_b);
int		check_second_half_b(t_node *current_a, t_stack *stack_b);
t_moves	*check_head_a(t_node *head_a, t_stack *stack_b);
void	check_moves_a(t_stack *stack_a, t_stack *stack_b,
			t_moves **current_moves);
void	reset_moves(t_moves **moves);
void	add_moves(t_moves *moves, int inst, int quantity);
t_map	*create_map_element(int key, int value);
void	free_moves(t_moves *moves);
void 	apply_moves(t_moves *moves, t_node **stack_a, t_node **stack_b,
			t_node **instr_queue);
void	print_queue(t_node	*instr_queue);
void	sort_stack_b(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
				  t_node **instr_queue);
void	pass_to_stack_a(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
					 t_node **instr_queue);
void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_moves **moves,
				  t_node **instr_queue);
void	fill_initial_stack_push_swap(int i, char **str, t_node **a);
void	build_input_push_swap(int size, char **argv, t_stack *stack_a);

// ------------------------------ test functions ------------------------------

int		node_size(t_node *head);
void	display(t_node *head, char *name);
void	display_qu(t_node *head, char *name);
void	display_step(t_node *stack_a, t_node *stack_b, t_node *sorted_stack,
				int count, int inst); // test function, borrar despues
void	display_moves(t_moves *moves);

void check_duplicates(t_node *stack);
#endif