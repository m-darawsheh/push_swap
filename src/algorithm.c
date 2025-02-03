/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:17:52 by ataher            #+#    #+#             */
/*   Updated: 2025/02/03 13:21:46 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;

	temp = stack->head->content;
	stack->head->content = stack->head->next->content;
	stack->head->next->content = temp;
	ft_printf("s%c\n", stack->name);
}

static void	sort_stack_three(t_stack *stack)
{
	int	one;
	int	two;
	int	three;

	one = stack->head->content;
	two = stack->head->next->content;
	three = stack->head->next->next->content;
	if (one < two && two > three && one < three)
	{
		(void)(stack->shift(stack, -1) | ft_printf("r%c\n", stack->name));
		swap_stack(stack);
		(void)(stack->shift(stack, 1) | ft_printf("rr%c\n", stack->name));
	}
	else if (one > two && two < three && one < three)
		swap_stack(stack);
	else if (one < two && two > three && one > three)
		(void)(stack->shift(stack, 1) | ft_printf("rr%c\n", stack->name));
	else if (one > two && one > three && two < three)
		(void)(stack->shift(stack, -1) | ft_printf("r%c\n", stack->name));
	else if (one > two && one > three && two > three)
	{
		swap_stack(stack);
		(void)(stack->shift(stack, 1) | ft_printf("rr%c\n", stack->name));
	}
}

void	stack_push_to(t_stack *stack_1, t_stack *stack_2)
{
	stack_2->insert(stack_2, node_dup(stack_1->head), 0);
	stack_1->pop(stack_1, 0);
	ft_printf("p%c\n", stack_2->name);
}

void	shift_sort_stack(t_stack *stack)
{
	t_node	*min;
	int		routations;
	int		reverse_rotations;

	min = get_min(*stack);
	routations = calc_rotation(stack->size,
			stack->find(*stack, min->content));
	reverse_rotations = calc_reverse_rotation(stack->size,
			stack->find(*stack, min->content));
	if (routations < reverse_rotations)
		while (routations--)
			(void)(stack->shift(stack, -1) | ft_printf("r%c\n", stack->name));
	else
		while (reverse_rotations--)
			(void)(stack->shift(stack, 1) | ft_printf("rr%c\n", stack->name));
}

void	sort_less_then_three(t_stack *stack)
{
	if (stack->size == 3)
		sort_stack_three(stack);
	else if (stack->size == 2 && !is_sorted(*stack))
		(void)(stack->shift(stack, 1) | ft_printf("rr%c\n", stack->name));
}
