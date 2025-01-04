/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:18:44 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 10:24:41 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_arg(int argc, char *argv[], t_stack *stack)
{
	int	i;

	check_if_char(argc, argv);
	check_if_duplicate(argc, argv);
	check_if_max_min(argc, argv);
	error_sign(argc, argv);
	i = 1;
	while (i < argc)
	{
		t_node *node = node_init(my_atoi(argv[i]));
		stack->insert(stack, node, -1);
		i++;
	}
}
