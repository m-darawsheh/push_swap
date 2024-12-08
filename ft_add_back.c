/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/08 09:53:24 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_node **head, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		free_protection(new_node);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		t_node	*last;

		last = *head;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

void ft_add_front(t_node **head, int data)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		free_protection(new_node);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
