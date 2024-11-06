/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/06 10:58:54 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head;

	head = NULL;
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
	parse_arg(argc, argv, &head);
	while (head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("SUCCESS!\n");
	return (0);
}
