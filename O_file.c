/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 11:51:40 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	delete_first_node(t_node	**node)
{
	t_node	*temp;
	temp = *node;
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



void	swap_last_two(t_node	**head)
{
	if (!head || !(*head) || !(*head)->next)
	{
		printf("stack is empty\n");
		exit(0);
	}
	t_node		*first;
	t_node		*second_one;
	int			temp;

	first = *head;
	second_one = first->next;
	temp = first->data;
	first->data = second_one->data;
	second_one->data = temp;
}


void	push_to_node(t_node	**stack1, t_node	**stack2)
{
	t_node *temp;
	int data;
	if (!stack1 || !(*stack1))
	{
		printf("cannot push, stack is empty\n");
		exit(0);
	}

	temp = *stack1;
	data = temp->data;
	delete_first_node(stack1);
	ft_add_front(stack2, data);
}
