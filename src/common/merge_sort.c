/*
** Created by dsalaman on 2021/04/03
*/

#include "push_swap.h"

// Merge two doubly-linked lists using recursion

t_node	*merge(t_node *first, t_node *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data == second->data)
	{
		error_exit();
		return (NULL);
	}
	else if (first->data < second->data)
	{
		first->prev = merge(first->prev, second);
		first->prev->next = first;
		first->next = NULL;
		return (first);
	}
	else
	{
		second->prev = merge(first, second->prev);
		second->prev->next = second;
		second->next = NULL;
		return (second);
	}
}

// Split a doubly-linked list (DLL) into 2 DLLs of half size
// This program uses "prev" because it starts on the top of the stack

t_node	*split_merge_sort(t_node *head)
{
	t_node	*fast;
	t_node	*slow;
	t_node	*temp;

	fast = head;
	slow = head;
	while (fast->prev && fast->prev->prev)
	{
		fast = fast->prev->prev;
		slow = slow->prev;
	}
	temp = slow->prev;
	slow->prev = NULL;
	return (temp);
}

// Apply merge-sort algorithm

t_node	*merge_sort(t_node *head)
{
	t_node	*second;

	second = NULL;
	if (!head || !head->prev)
		return (head);
	second = split_merge_sort(head);
	head = merge_sort(head);
	second = merge_sort(second);
	return (merge(head, second));
}
