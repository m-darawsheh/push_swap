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

void swap_last_two(t_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return;
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

int last_data(t_node *node)
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



void	push_to_a(t_node **head,t_node **b)
{
	t_node *temp;
	int data;
	if (!b)
	{
		printf("list b is empty\n");
		exit(0);
	}
	temp = *b;
	while (temp->next)
		temp = temp->next;
	data = temp->data;
	printf("the last data from b is ::: %d\n", data);
	// check list b befor delete last node
	ft_add_back(head, data);
	delete_last_node(b);
}