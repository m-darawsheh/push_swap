/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/02 09:56:53 by mdarawsh         ###   ########.fr       */
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
	// print_node(a);
	// print_node(b);

	// push_to_node(&a, &b);
	// push_to_node(&a, &b);
	// push_to_node(&a, &b);

	// reverse_rotate_node(&b);

	algo(&a, &b);

	// print_node(a);
	// print_node(b);
	// print_node(a);
	// is_sorted_a(a);
	return (0);
}


