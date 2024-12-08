/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/08 12:17:48 by ataher           ###   ########.fr       */
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

int	node_len(t_node *node)
{
	int	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}


int		find_index(t_node *node, int data)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->data == data)
			return (i);
		node = node->next;
		i++;
	}
	printf( "error input data\n");
	return (-1);
}

bool	is_sorted(t_node *node)
{
	while (node->next)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	parse_arg(argc, argv, &a);
	algo(&a, &b);
	free_protection(a);
	free_protection(b);
	return (0);
}

