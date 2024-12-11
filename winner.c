/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:52:05 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 12:12:25 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_numberes(t_node *temp, t_node *a, t_node *b, int data)
{
	int			index;
	int			len;
	t_number	x;

	len = node_len(b);
	index = find_index(b, data);
	x.rotation = calc_rotation(len, index);
	x.reverse_rotation = calc_reverse_rotation(len, index);
	if (x.rotation < x.reverse_rotation)
		x.for_right_place = x.rotation;
	else
		x.for_right_place = x.reverse_rotation;
	len = node_len(a);
	index = find_index(a, temp->data);
	x.rotation_a = calc_rotation(len, index);
	x.reverse_rotation_a = calc_reverse_rotation(len, index);
	if (x.rotation_a < x.reverse_rotation_a)
		x.for_top = x.rotation_a;
	else
		x.for_top = x.reverse_rotation_a;
	x.total = x.for_top + x.for_right_place;
	return (x.total);
}

t_node	*winner_node(t_node	*a, t_node	*b)
{
	int			min_opration;
	int					x;
	int				data;
	t_node		*winner;
	t_node		*temp;

	winner = NULL;
	temp = a;
	min_opration = INT_MAX;
	while (temp)
	{
		x = 0;
		data = right_place(temp, b);
		x = find_numberes(temp, a, b, data);
		if (x < min_opration)
		{	
			min_opration = x;
			winner = temp;
		}
		temp = temp->next;
	}
	return (winner);
}
