/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   O_f2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:51:37 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 16:19:32 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_node(t_node	**a)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || !(*a) || !(*a)->next)
	{
		write(2, "list is empty\n", 14);
		exit(2);
	}
	second_last = *a;
	while (second_last->next && second_last->next->next)
	{
		second_last = second_last->next;
	}
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
}

void	ss(t_node **a, t_node **b)
{
	swap_last_two(a);
	swap_last_two(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate_node(a);
	rotate_node(b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate_node(a);
	reverse_rotate_node(b);
}

void	rotate_node(t_node **node)
{
	t_node	*first;
	t_node	*last;

	if (!node || !(*node) || !(*node)->next)
	{
		write(2, "list is empty\n", 14);
		exit(2);
	}
	first = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	last = *node;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
