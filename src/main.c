/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:26 by ataher            #+#    #+#             */
/*   Updated: 2025/02/03 13:21:05 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	start_turquoise_algorithm(t_stack *a, t_stack *b)
{
	t_cost	cost_best;

	if (a->size <= 3)
	{
		sort_less_then_three(a);
		return ;
	}
	stack_push_to(a, b);
	stack_push_to(a, b);
	while (a->size > 3)
	{
		cost_best = get_best_cost(a, b);
		exe_cost(cost_best, a, b);
		stack_push_to(a, b);
	}
	sort_less_then_three(a);
	while (b->head)
	{
		cost_best = get_best_cost(b, a);
		exe_cost(cost_best, b, a);
		stack_push_to(b, a);
	}
	shift_sort_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init('a');
	b = stack_init('b');
	if (!a || !b)
		exit_program(a, b, NULL);
	parse_arg(argc, argv, a, b);
	start_turquoise_algorithm(a, b);
	a->clear(a);
	b->clear(b);
	return (0);
}
