/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:16:39 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:52 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*min;

	min = get_min(*stack_a);
	push_min(stack_a, stack_b, min);
	s_kh(stack_a);
	push_to_node(stack_b, stack_a);
	write(1, "pa\n", 3);
	free_protection(stack_a);
	free_protection(stack_b);
	exit (0);
}

void	swap_and_print(t_node **a)
{
	swap_last_two(a);
	write (1, "sa\n", 3);
	free_protection(a);
	exit (0);
}
