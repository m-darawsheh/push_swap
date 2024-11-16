/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/09 12:46:47 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_node(t_node *node)
{
	while (node)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}

int	find_min_data(t_node *node)
{
	t_node	*min;

	min = node -> next;
	while (node)
	{
		if (node->data < min->data)
			min = node;
		node = node->next;
	}
	if (min-> prev == NULL)
		return (1);
	else if (min->next == NULL)
		return (3);
	return (2);
}

int find_min_number(char *argv[])
{
	int i;
	int min;
	
	i = 0;
	while (argv[i])
	{
		if (i == 0)
			min = my_atoi(argv[i]);
		else if (my_atoi(argv[i]) < min)
			min = my_atoi(argv[i]);
		i++;
	}
	return (i);
	;
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


void	S_kh(t_node **head)
{
	int	place_min_data;

	place_min_data = find_min_data(*head);
	if (is_sorted(*head))
		return ;
	else if (place_min_data == 1)
		swap_last_two(head);
	else if (find_min_data(*head) == 2)
	{
		reverse_rotate_node(head);
		if (is_sorted(*head))
			return ;
		else
			swap_last_two(head);
	}
	else if (find_min_data(*head) == 3)
	{
		rotate_node(head);
		if (is_sorted(*head))
			return ;
		else
			swap_last_two(head);
	}
}

int	main(int argc, char **argv)
{
	t_node	*head;
	// t_node	*b;
	
	head = NULL;
	// b = NULL;
	if (argc < 3)
	{
		if (argc == 2)
		{
			error_sign(argc, argv);
			check_if_char(argc, argv);
			check_if_max_min(argc, argv);
		}		
		return (0);
	}


	// parse_arg(argc, argv, &b);
	parse_arg(argc, argv, &head);
	S_kh(&head);
	print_node(head);
	// printf ("before delete last node from a list :\n");
	// print_node(head);
	
	// printf ("after delete last node\n");
	// delete_last_node(&head);
	// print_node(head);
	// printf("push to a\n");
	// push_to_a(&head, &b);
	// print_node(head);
	
	// printf("list b ::::::::: \n");
	// print_node(b);
	
	// printf("try to add back\n");
	// ft_add_back(&b, 7777);
	// print_node(b);
	// printf("swap swap swap\n");
	// swap_last_two(&head);
	// print_node(head);
	// printf("SUCCESS a!\n");

	// printf("rotate a\n");
	// rr(&head, &b);
	// printf("a list ::: \n");
	// print_node(head);
	// printf("b list ::: \n");
	// print_node(b);
	return (0);
}
