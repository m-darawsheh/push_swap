/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 14:32:24 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	print_node(t_node *node)
// {
// 	while (node)
// 	{
// 		printf("%d\t", node->data);
// 		node = node->next;
// 	}
// 	printf("\n");
// }

// int	node_len(t_node *node)
// {
// 	int	len;

// 	len = 0;
// 	while (node)
// 	{
// 		len++;
// 		node = node->next;
// 	}
// 	return (len);
// }




// bool	is_sorted(t_node *node)
// {
// 	while (node->next)
// 	{
// 		if (node->data > node->next->data)
// 			return (false);
// 		node = node->next;
// 	}
// 	return (true);
// }

int	main(int argc, char **argv)
{
	t_stack a = stack_init();
	t_stack b = stack_init();

	parse_arg(argc, argv, &a);

	// a.log.simple(a);
	// b.log.simple(b);

	// b.insert(&b, node_dup(a.head), 0);
	// a.pop(&a, 0);

	// b.insert(&b, node_dup(a.head), 0);
	// a.pop(&a, 0);


	algo(&a, &b);

	// a.log.simple(a);
	// b.log.simple(b);

	a.clear(&a);
	b.clear(&b);
	return (0);
}

