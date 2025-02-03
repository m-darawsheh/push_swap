/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:18:44 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 17:11:02 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_arg(int argc, char *argv[], t_stack *stack_1, t_stack *stack_2)
{
	int		i;
	t_node	*node;

	check_if_char(argc, argv, stack_1, stack_2);
	check_if_duplicate(argc, argv, stack_1, stack_2);
	check_if_max_min(argc, argv, stack_1, stack_2);
	error_sign(argc, argv, stack_1, stack_2);
	i = 1;
	while (i < argc)
	{
		node = node_init(my_atoi(argv[i], stack_1, stack_2));
		if (!node)
			exit_program(stack_1, stack_2, NULL);
		stack_1->insert(stack_1, node, -1);
		i++;
	}
}
