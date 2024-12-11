/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:32 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 17:46:25 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_ra(t_node **a)
{
	rotate_node(a);
	rotate_node(a);
	printf("ra\n");
	printf("ra\n");
}
void	double_rra(t_node **a)
{
	reverse_rotate_node(a);
	reverse_rotate_node(a);
	printf("rra\n");
	printf("rra\n");
}

void	push_max(t_node **a, t_node **b, t_node *max)
{
	int	index;

	index = find_index(*a, max->data);
	if (index == 1)
	{
		rotate_node(a);
		printf("ra\n");
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
		printf("rra\n");
	}
	push_to_node(a, b);
	printf("pb\n");
}
void	push_min(t_node **a, t_node **b, t_node *min)
{
	int	index;

	index = find_index(*a, min->data);
	if (index == 1)
	{
		rotate_node(a);
		printf("ra\n");
	}
	else if (index == 2)
	{
		double_ra(a);
	}
	else if (index == 3)
	{
		reverse_rotate_node(a);
		printf("rra\n");
	}
	push_to_node(a, b);
	printf("pb\n");
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
	push_to_node(b, a);
	push_to_node(b, a);
	printf("pa\n");
	printf("pa\n");
	rotate_node(a);
	printf("ra\n");
	free_protection(a);
	free_protection(b);
	return ;
}
