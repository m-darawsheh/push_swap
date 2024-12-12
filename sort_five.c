/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:32 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 16:15:41 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_ra(t_node **a)
{
	rotate_node(a);
	rotate_node(a);
	write(1, "ra\n", 3);
	write(1, "ra\n", 3);
}

void	double_rra(t_node **a)
{
	reverse_rotate_node(a);
	reverse_rotate_node(a);
	write(1, "rra\n", 4);
	write(1, "rra\n", 4);
}

void	push_max(t_node **a, t_node **b, t_node *max)
{
	int	index;

	index = find_index(*a, max->data);
	if (index == 1)
	{
		rotate_node(a);
		write(1, "ra\n", 3);
	}
	else if (index == 2)
	{
		double_ra(a);
	}
	else if (index == 3)
	{
		double_rra(a);
	}
	else if (index == 4)
	{
		reverse_rotate_node(a);
		write(1, "rra\n", 4);
	}
	push_to_node(a, b);
	write(1, "pb\n", 3);
}

void	push_min(t_node **a, t_node **b, t_node *min)
{
	int	index;

	index = find_index(*a, min->data);
	if (index == 1)
	{
		rotate_node(a);
		write(1, "ra\n", 3);
	}
	else if (index == 2)
	{
		double_ra(a);
	}
	else if (index == 3)
	{
		reverse_rotate_node(a);
		write(1, "rra\n", 4);
	}
	push_to_node(a, b);
	write(1, "pb\n", 3);
}

void	m_dr(t_node **a, t_node **b)
{
	t_node	*min;
	t_node	*max;

	min = get_min(*a);
	max = get_max(*a);
	push_max(a, b, max);
	push_min(a, b, min);
	s_kh(a);
	double_push_a(b, a);
	rotate_node(a);
	write(1, "ra\n", 3);
	free_protection(a);
	free_protection(b);
	return ;
}
