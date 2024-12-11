/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:58 by mdarawsh         ###   ########.fr       */
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
void	check_first_two(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
	{
		swap_last_two(a);
		printf("sa\n");
	}
}

void	s_kh(t_node **a)
{
	t_node	*min;

	min = get_min(*a);
	if (min->prev == NULL)
	{
		rotate_node(a);
		printf("ra\n");	
		check_first_two(a);
		reverse_rotate_node(a);
		printf("rra\n");
	}
	if (min->next == NULL)
	{
		check_first_two(a);
		reverse_rotate_node(a);
		printf("rra\n");
	}
	if(min->prev && min->next)
	{
		reverse_rotate_node(a);
		printf("rra\n");
		check_first_two(a);
		reverse_rotate_node(a);
		printf("rra\n");
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 2)
		return (0);
	parse_arg(argc, argv, &a);
	if (is_sorted_a (a))
	{
		free_protection(&a);
		return (0);
	}
	// check_first_two(&a);
	if(argc == 4)
	{
		s_kh(&a);
		free_protection(&a);
		return (0);
	}
	if (argc == 6)
	{
		m_dr(&a, &b);
		
		return (0);
	}
	algo(&a, &b);
	free_protection(&a);
	free_protection(&b);
	return (0);
}
