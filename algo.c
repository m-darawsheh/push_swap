/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:50:28 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 16:01:50 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotations_a(t_number x, t_node **a)
{
	int	i;

	i = 0;
	while (i < x.for_top)
	{
		if (x.rotation_a < x.reverse_rotation_a)
		{
			rotate_node(a);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate_node(a);
			write(1, "rra\n", 4);
		}
		i++;
	}
}

void	do_rotations_b(t_number x, t_node **b)
{
	int	i;

	i = 0;
	while (i < x.for_right_place)
	{
		if (x.rotation < x.reverse_rotation)
		{
			rotate_node(b);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate_node(b);
			write(1, "rrb\n", 4);
		}
		i++;
	}
}

void	make_b_inverse(t_node **b)
{
	t_node			*max;
	t_number		x;

	max = get_max(*b);
	x.rotation = calc_rotation(node_len(*b), find_index(*b, max->data));
	x.reverse_rotation = calc_rr(node_len(*b), find_index(*b, max->data));
	if (x.rotation < x.reverse_rotation)
		x.for_top = x.rotation;
	else
		x.for_top = x.reverse_rotation;
	while (x.for_top)
	{
		if (x.rotation < x.reverse_rotation)
		{
			rotate_node(b);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate_node(b);
			write(1, "rrb\n", 4);
		}
		x.for_top--;
	}
}

void	pushing(t_node **b, t_node **a)
{
	int	push;
	int	i;

	push = node_len(*b);
	i = 0;
	while (i < push)
	{
		push_to_node(b, a);
		write(1, "pa\n", 3);
		i++;
	}
}

void	algo(t_node **a, t_node **b)
{
	t_node		*winner;
	int			data;
	t_number	x;

	winner = NULL;
	if (node_len(*a) == 5)
	{
		m_dr(a, b);
		return ;
	}
	double_push_b(a, b);
	while (!the_list_is_empty(*a))
	{
		winner = winner_node(*a, *b);
		data = right_place(winner, *b);
		x = find_rights(winner, *a, *b, data);
		do_rotations_a(x, a);
		do_rotations_b(x, b);
		push_to_node(a, b);
		write(1, "pb\n", 3);
	}
	make_b_inverse(b);
	pushing(b, a);
}
