/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_places.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:22:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 15:26:20 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	find_rights(t_node *temp, t_node *a, t_node *b, int data)
{
	t_number	x;

	x.rotation = calc_rotation(node_len(b), find_index(b, data));
	x.reverse_rotation = calc_rr(node_len(b), find_index(b, data));
	if (x.rotation < x.reverse_rotation)
		x.for_right_place = x.rotation;
	else
		x.for_right_place = x.reverse_rotation;
	x.rotation_a = calc_rotation(node_len(a), find_index(a, temp->data));
	x.reverse_rotation_a = calc_rr(node_len(a), find_index(a, temp->data));
	if (x.rotation_a < x.reverse_rotation_a)
		x.for_top = x.rotation_a;
	else
		x.for_top = x.reverse_rotation_a;
	x.total = x.for_top + x.for_right_place;
	return (x);
}
