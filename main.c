/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/08 10:56:49 by ataher           ###   ########.fr       */
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
	return (find_index(node, min->data));
}

int find_max_data(t_node *node)
{
	t_node	*max;

	max = node -> next;
	while (node)
	{
		if (node->data > max->data)
			max = node;
		node = node->next;
	}
	return (find_index(node, max->data));
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

void	push_min(t_node	**head, t_node	**b, int	place_min_data)
{
	if (place_min_data < 3)
	{
		int	i;

		i = 0;
		while (i < place_min_data)
		{
			reverse_rotate_node(head);
			i++;
		}

	}
	else
	{
		int	j;

		j = 4;
		while (j >= place_min_data)
		{
			rotate_node(head);
			j--;
		}
	}
	push_to_node(b, head);
}

void	push_max(t_node	**head, t_node	**b, int	place_max_data)
{
	if (place_max_data == 1)
	{
		reverse_rotate_node(head);
	}
	else if (place_max_data == 2)
	{
		rotate_node(head);
		rotate_node(head);
	}
	else if (place_max_data == 3)
	{
		rotate_node(head);
	}
	push_to_node(b, head);
}

void	M_dr(t_node **head, t_node **b)
{
	int	place_min_data;
	int	place_max_data;

	place_min_data = find_min_data(*head);
	place_max_data = find_max_data(*head);
	if (is_sorted(*head))
		return ;
	push_min(head, b, place_min_data);
	push_max(head, b, place_max_data);
	S_kh(head);
	push_to_node(head, b);
	push_to_node(head, b);
	rotate_node(head);

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

	// // rotate_node(&a);
	// // reverse_rotate_node(&a);
	// push_to_node(&a, &b);
	// push_to_node(&a, &b);

	// print_node(a);
	// print_node(b);

	algo(&a, &b);


	// parse_arg(argc, argv, &b);
	// int i = node_len(head);
	// printf("len is %d\n", i);

	// push_to_node(&head, &b);
	// push_to_node(&head, &b);
	// print_node(b);
	// swap_last_two(&b);
	// print_node(b);



	// push_to_node(&head, &b);
	// print_node(b);
	// reverse_rotate_node(&b);
	// print_node(b);
	// rotate_node(&b);
	// print_node(b);


	// reverse_rotate_node(&head);
	// print_node(head);

	// rotate_node(&head);
	// print_node(head);

	// // print_node(b);
	// push_to_node(&head, &b);
	// print_node(head);
	// print_node(b);








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


