/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:50:52 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 12:36:14 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	the_list_is_empty(t_node *stack)
{
	if (!stack)
		return (true);
	return (false);
}

bool	is_sorted_a(t_node *node)
{
	t_node	*temp;

	temp = node;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
		{
			printf("the list is not sorted\n");
			return (false);
		}
		temp = temp->next;
	}
	printf("the list is sorted\n");
	return (true);
}

int	right_place(t_node *a, t_node *b)
{
	t_node	*min;
	t_node	*temp;

	min = get_min(b);
	temp = min;
	while (a->data > min->data)
	{
		if (min->prev)
			min = min->prev;
		else
			min = get_last(b);
		if (temp->data == min->data)
		{
			if (min->next)
				return (min->next->data);
			else
				return (b->data);
		}
	}
	if (min->next)
		return (min->next->data);
	else
		return (b->data);
}
