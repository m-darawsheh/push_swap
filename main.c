/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 13:03:51 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	while (node)
	{
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	parse_arg(argc, argv, &a);
	algo(&a, &b);
	free_protection(&a);
	free_protection(&b);
	return (0);
}
