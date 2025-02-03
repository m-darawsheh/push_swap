/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turquoise_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:18:24 by ataher            #+#    #+#             */
/*   Updated: 2025/02/03 13:19:01 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_cost	calc_cost(t_node node, t_stack *stack_1, t_stack *stack_2)
{
	t_cost	cost;
	t_node	*min;

	min = get_postion(node, stack_1, stack_2);
	cost.r_to = calc_rotation(stack_2->size,
			stack_2->find(*stack_2, min->content));
	cost.rr_to = calc_reverse_rotation(stack_2->size,
			stack_2->find(*stack_2, min->content));
	cost.r_from = calc_rotation(stack_1->size,
			stack_1->find(*stack_1, node.content));
	cost.rr_from = calc_reverse_rotation(stack_1->size,
			stack_1->find(*stack_1, node.content));
	cost.rr = get_min_int(cost.r_to, cost.r_from);
	cost.rrr = get_min_int(cost.rr_to, cost.rr_from);
	cost.collective_cost_test1 = get_min_int(cost.r_to, cost.rr_to)
		+ get_min_int(cost.r_from, cost.rr_from);
	cost.collective_cost_test2 = cost.rr + (cost.r_to - cost.rr)
		+ (cost.r_from - cost.rr);
	cost.collective_cost_test3 = cost.rrr
		+ (cost.rr_to - cost.rrr) + (cost.rr_from - cost.rrr);
	cost.collective_cost = get_min_int(cost.collective_cost_test1,
			get_min_int(cost.collective_cost_test2,
				cost.collective_cost_test3));
	return (cost);
}

static void	exe_cost_test1(t_cost cost, t_stack *stack_1, t_stack *stack_2)
{
	if (cost.r_from < cost.rr_from)
	{
		stack_1->shift(stack_1, -cost.r_from);
		while (cost.r_from--)
			ft_printf("r%c\n", stack_1->name);
	}
	else
	{
		stack_1->shift(stack_1, cost.rr_from);
		while (cost.rr_from--)
			ft_printf("rr%c\n", stack_1->name);
	}
	if (cost.r_to < cost.rr_to)
	{
		stack_2->shift(stack_2, -cost.r_to);
		while (cost.r_to--)
			ft_printf("r%c\n", stack_2->name);
	}
	else
	{
		stack_2->shift(stack_2, cost.rr_to);
		while (cost.rr_to--)
			ft_printf("rr%c\n", stack_2->name);
	}
}

void	exe_cost(t_cost cost, t_stack *stack_1, t_stack *stack_2)
{
	if (cost.collective_cost == cost.collective_cost_test1)
		exe_cost_test1(cost, stack_1, stack_2);
	else if (cost.collective_cost == cost.collective_cost_test2)
	{
		stack_1->shift(stack_1, -cost.rr);
		stack_2->shift(stack_2, -cost.rr);
		cost.r_to -= cost.rr;
		cost.r_from -= cost.rr;
		while (cost.rr--)
			ft_printf("rr\n");
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, stack_1, stack_2);
	}
	else if (cost.collective_cost == cost.collective_cost_test3)
	{
		stack_1->shift(stack_1, cost.rrr);
		stack_2->shift(stack_2, cost.rrr);
		cost.rr_to -= cost.rrr;
		cost.rr_from -= cost.rrr;
		while (cost.rrr--)
			ft_printf("rrr\n");
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, stack_1, stack_2);
	}
}

t_cost	get_best_cost(t_stack *stack_1, t_stack *stack_2)
{
	t_cost	cost_best;
	t_node	*stack_1_node;
	t_cost	cost;

	stack_1_node = stack_1->head;
	cost_best.collective_cost = -1;
	while (stack_1_node)
	{
		cost = calc_cost(*stack_1_node, stack_1, stack_2);
		if (cost_best.collective_cost == -1)
			cost_best = cost;
		if (cost.collective_cost < cost_best.collective_cost)
			cost_best = cost;
		stack_1_node = stack_1_node->next;
	}
	return (cost_best);
}

int	is_sorted(t_stack stack)
{
	t_node	*node;

	node = stack.head;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}
