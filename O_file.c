/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/09 12:19:28 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	last_data(t_node *node)
{
	if (!node)
	{
		printf("list is empty\n");
		exit(0);
	}
	while (node->next)
		node = node->next;
	return (node->data);
}

void	delete_last_node(t_node **node)
{
	t_node *temp = *node;

	if (*node == NULL)
		return;
	if (temp->next == NULL) {
		free(temp);
		*node = NULL;
		return;
	}
	while (temp->next && temp->next->next) {
		temp = temp->next;
	}
	t_node *last_node = temp->next;
	temp->next = NULL;
	free(last_node);
}

void delete_first_node(t_node **node)
{
	t_node *temp = *node;

	if (*node == NULL)
		return;
	if ((*node)->next == NULL) {
		free(*node);
		*node = NULL;
		return;
	}
	*node = (*node)->next;
	(*node)->prev = NULL;
	free(temp);
}



void swap_last_two(t_node **head)
{
	if (!head || !(*head) || !(*head)->next)
	{
		printf("stack is empty\n");
		exit(0);
	}
	t_node		*last;
	t_node		*second_last;
	int			temp;

	last = *head;
	while (last->next)
	{
		last = last->next;
	}
	second_last = last->prev;
	temp = last->data;
	last->data = second_last->data;
	second_last->data = temp;
}


void	push_to_node(t_node **stack1, t_node **stack2)
{
	t_node *temp;
	int data;
	// if (!stack1 || !(*stack1))
	// {
	// 	printf("from stack is empty\n");
	// 	exit(0);
	// }

	// push the first element from stack1 to first element of stack2
	temp = *stack1;
	data = temp->data;
	delete_first_node(stack1);
	// printf("hi\n");
	ft_add_front(stack2, data);
}

void reverse_rotate_node(t_node **a)
{
	t_node *last;
	t_node *second_last;

	if (!a || !(*a) || !(*a)->next)
	{
		printf("list is empty\n");
		exit(0);
	}

	second_last = *a;
	while (second_last->next && second_last->next->next)
	{
		second_last = second_last->next;
	}


	last = second_last->next;
	second_last->next = NULL;

	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
}

void	ss(t_node **a, t_node **b)
{
	swap_last_two(a);
	swap_last_two(b);
}

void rr(t_node **a, t_node **b)
{
	rotate_node(a);
	rotate_node(b);
}

void rrr(t_node **a, t_node **b)
{
	reverse_rotate_node(a);
	reverse_rotate_node(b);
}



void rotate_node(t_node **node)
{
	t_node	*first;
	t_node	*last;

	if (!node || !(*node) || !(*node)->next)
	{
		printf("list is empty\n");
		exit(0);
	}

	first = *node;

	*node = (*node)->next;
	(*node)->prev = NULL;

	last = *node;
	while (last->next)
		last = last->next;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}