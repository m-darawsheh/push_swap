/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:41 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 16:33:24 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_max_min(int argc, char *argv[], t_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (my_strlen(argv[i]) > 10)
		{
			write(2, "Error\n", 6);
			free_protection(head);
			exit(2);
		}
		if (my_atoi(argv[i]) > 2147483647 || my_atoi(argv[i]) < -2147483648)
		{
			write(2, "Error\n", 6);
			free_protection(head);
			exit(2);
		}
		i++;
	}
}

void	check_if_duplicate(int argc, char *argv[], t_node **head)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && my_atoi(argv[i]) == my_atoi(argv[j]))
			{
				write(2, "Error\n", 6);
				free_protection(head);
				exit(2);
			}
			j++;
		}
		i++;
	}
}

void	check_if_char(int argc, char *argv[], t_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isalpha_edit(argv[i]))
		{
			write(2, "Error\n", 6);
			free_protection(head);
			exit(2);
		}
		i++;
	}
}

void	error_sign(int argc, char *argv[], t_node **head)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') && argv[i][1] == '\0')
		{
			write(2, "Error\n", 6);
			free_protection(head);
			exit(2);
		}
		i++;
	}
}
