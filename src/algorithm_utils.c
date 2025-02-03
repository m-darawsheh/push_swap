/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:17 by ataher            #+#    #+#             */
/*   Updated: 2025/02/03 13:16:35 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_min(t_stack stack)
{
	t_node	*min;

	min = stack.head;
	while (stack.head)
	{
		if (stack.head->content < min->content)
			min = stack.head;
		stack.head = stack.head->next;
	}
	return (min);
}

int	calc_rotation(int length, int index)
{
	(void)length;
	return (index);
}

int	calc_reverse_rotation(int length, int index)
{
	if (index == 0)
		return (0);
	return (length - index);
}

int	get_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_node	*get_postion(t_node node, t_stack *stack_1, t_stack *stack_2)
{
	t_node	*postion;
	t_node	*temp;

	postion = get_min(*stack_2);
	temp = postion;
	while (node.content > postion->content)
	{
		if (postion->prev && stack_1->name == 'a')
			postion = postion->prev;
		else if (!postion->prev && stack_1->name == 'a')
			postion = stack_2->tail;
		else if (postion->next && stack_1->name == 'b')
			postion = postion->next;
		else if (!postion->next && stack_1->name == 'b')
			postion = stack_2->head;
		if (temp->content == postion->content)
			break ;
	}
	if (postion->next && stack_1->name == 'a')
		postion = postion->next;
	else if (!postion->next && stack_1->name == 'a')
		postion = stack_2->head;
	return (postion);
}
