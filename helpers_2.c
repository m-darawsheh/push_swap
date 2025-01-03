/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:51:21 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 14:53:08 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min(t_node	*stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_node	*get_max(t_node	*stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_node	*get_last(t_node	*stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	calc_rotation(int length, int index)
{
	(void)length;
	return (index);
}

int	calc_rr(int length, int index)
{
	if (index == 0)
		return (0);
	return (length - index);
}
