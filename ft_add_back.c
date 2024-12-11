/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 12:16:10 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*last;

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
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

void	ft_add_front(t_node **head, int data)
{
	t_node	*new_node;
	t_node	*temp;

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
		temp = *head;
		*head = new_node;
		new_node->next = temp;
		temp->prev = new_node;
	}
}
