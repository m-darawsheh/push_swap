/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:50:28 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 17:36:10 by mdarawsh         ###   ########.fr       */
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
			printf("ra\n");
		}
		else
		{
			reverse_rotate_node(a);
			printf("rra\n");
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
			printf("rb\n");
		}
		else
		{
			reverse_rotate_node(b);
			printf("rrb\n");
		}
		i++;
	}
}

void	make_b_inverse(t_node **b)
{
	t_node	*max;
	t_number	x;
	
	max = get_max(*b);
	x.rotation = calc_rotation(node_len(*b), find_index(*b, max->data));
	x.reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, max->data));
	if(x.rotation < x.reverse_rotation)
		x.for_top = x.rotation;
	else
		x.for_top = x.reverse_rotation;
	int i = 0;
	while (i < x.for_top)
	{
		if (x.rotation < x.reverse_rotation)
		{
			rotate_node(b);
			printf("rb\n");
		}
		else
		{
			reverse_rotate_node(b);
			printf("rrb\n");
		}
		i++;
	}
}


void pushing(t_node **b, t_node **a)
{
	int	push;
	int	i;

	push = node_len(*b);
	i = 0;
	while (i < push)
	{
		push_to_node(b, a);
		printf("pa\n");
		i++;
	}
}

void	algo(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	printf("pb\n");
	printf("pb\n");

	while (!the_list_is_empty(*a))
	{
		t_node *winner = winner_node(*a, *b);
		int data = right_place(winner, *b);

		t_number x = find_rights(winner, *a, *b, data);

		do_rotations_a(x, a);
		do_rotations_b(x, b);
		push_to_node(a, b);
		printf("pb\n");
	}
	make_b_inverse(b);
	pushing(b, a);

}
