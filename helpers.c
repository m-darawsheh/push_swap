/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:51:24 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 11:57:03 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_len(t_node *node)
{
	int	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int	find_index(t_node *node, int data)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->data == data)
			return (i);
		node = node->next;
		i++;
	}
	printf("error input dataaa\n");
	return (-1);
}

int	find_min_data(t_node *node)
{
	t_node	*min;

	min = node -> next;
	while (node)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	return (find_index(node, min->data));
}

int	find_max_data(t_node *node)
{
	t_node	*max;

	max = node -> next;
	while (node)
	{
		if (node->data > max->data)
			max = node;
		node = node->next;
	}
	return (find_index(node, max->data));
}

bool	is_sorted(t_node *node)
{
	t_node	*min;
	t_node	*temp;

	min = get_min(node);
	temp = min;
	while (true)
	{
		if (min->data > min->prev->data && min->prev->data != temp->data)
			return (false);
		min = min->prev;
		if (!min->prev)
		{
			min = get_last(node);
		}
		if (temp->data == min->data)
			return (true);
	}
}
