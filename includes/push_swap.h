/*
** Created by dsalaman on 2021/04/03
*/

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
	t_map			*inst;
}	t_moves;

typedef struct s_stack
{
	t_node		*nodes;
	int			size;
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
int		*pop(t_node **head);
int		*peek(t_node *head);
int		*deque(t_node **head);
void	push(t_node **head, int data);
void	enqueue(t_node **head, int data);
void	swap(t_node **head);
void	swap_multiple(t_node **head_a, t_node **head_b);
void	push_to_stack(t_node **from, t_node **to);
void	rotate(t_node **head);
void	rotate_multiple(t_node **head_a, t_node **head_b);
void	reverse(t_node **head);
void	reverse_multiple(t_node **head_a, t_node **head_b);
void	error_exit(void);
void	build_input(int size, char **argv, t_node **a, t_node **sorted);
void	fill_stacks(char *str, t_node **a, t_node **sorted);
t_node	*merge(t_node *first, t_node *second);
t_node	*split_merge_sort(t_node *head);
t_node	*merge_sort(t_node *head);
t_node	*create_element(int data);

// ------------------------------ checker -----------------------------------

int		read_instruction(char *input);
int		check_sort(t_node *stack_a, t_node *stack_b, t_node *sorted);
void	apply_instructions(t_node **stack_a, t_node **stack_b, int instr);
void	reset_input(t_node **stack_a, t_node **stack_b, t_node **sorted);
t_node	*get_instructions(void);
t_node	*sort_checker(t_node **stack_a, t_node **stack_b);

// ------------------------------ push_swap -----------------------------------

int		sorted(t_node *stack_a);
int		find_len_stack(t_node *head);
int		check_first_half_b(int current_a, t_stack *stack_b);
int		check_second_half_b(int current_a, t_stack *stack_b);
int		is_positionable(int current_a, int current_b, int next_b);
void	build_input_push_swap(int size, char **argv, t_stack *stack_a);
void	reset_input_push_swap(t_stack *stack_a, t_stack *stack_b);
void	clean_stack(t_node **stack);
void	print_instructions(int instr);
void	print_queue(t_node	*instr_queue);
void	reset_moves(t_moves **moves);
void	add_moves(t_moves *moves, int inst, int quantity);
void	free_moves(t_moves *moves);
void	apply_moves(t_moves *moves, t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue);
void	apply_three_num_rules(t_node *stack_a, t_node **instr_queue);
void	insertion_sort_stack_b(t_stack *stack_a, t_stack *stack_b
			t_node **instr_queue);
void	return_to_stack_a(t_stack *stack_a, t_stack *stack_b,
			t_node **instr_queue);
void	sort_stack_a(t_stack *stack_a, t_stack *stack_b, t_node **instr_queue);
void	apply_push_instruction(t_stack *from, t_stack *to, int inst,
			t_node **instr_queue);
void	check_first_half_a(int current_a, t_stack *stack_b, int index,
			t_moves **moves);
void	check_second_half_a(int current_a, t_stack *stack_b, int index,
			t_moves **moves);
t_map	*create_map_element(int key, int value);
t_node	*sort_stack(t_stack *stack_a, t_stack *stack_b);
t_moves	*check_head_a(t_node *head_a, t_stack *stack_b);
t_moves	*choose_moves(t_moves *current, t_moves *new);
t_moves	*get_best_moves(t_stack *stack_a, t_stack *stack_b,
			t_moves *current_moves);

// ------------------------------ test functions ------------------------------

int		node_size(t_node *head);
void	display(t_node *head, char *name);
void	display_qu(t_node *head, char *name);
void	display_step(t_node *stack_a, t_node *stack_b, t_node *sorted_stack,
			int count, int inst); // test function, borrar despues
void	display_moves(t_moves *moves);

#endif