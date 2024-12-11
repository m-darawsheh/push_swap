/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 11:21:52 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
