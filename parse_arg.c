/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:12 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/02 09:57:09 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg(int argc, char *argv[], t_node **head)
{
	int	i;

	check_if_char(argc, argv);
	check_if_duplicate(argc, argv);
	check_if_max_min(argc, argv);
	error_sign(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (!*head)
		{
			*head = malloc(sizeof(t_node));
			if (!*head)
				free_protection(*head);
			(*head)->data = my_atoi(argv[i]);
			(*head)->prev = NULL;
			(*head)->next = NULL;
		}
		else
			ft_add_back(head, my_atoi(argv[i]));
		i++;
	}
}
