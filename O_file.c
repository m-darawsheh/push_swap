/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/06 11:11:56 by mdarawsh         ###   ########.fr       */
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