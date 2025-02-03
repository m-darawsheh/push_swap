/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:39 by ataher            #+#    #+#             */
/*   Updated: 2025/01/22 02:22:21 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_rubbish_sign(const char *nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			return (true);
		}
		i++;
	}
	return (false);
}

void	check_if_max_min(int argc, char *argv[],
	t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (my_strlen(argv[i]) > 10)
		{
			ft_dprintf(2, "Error\n");
			exit_program(stack_1, stack_2, NULL);
		}
		if (my_atoi(argv[i], stack_1, stack_2) > 2147483647
			|| my_atoi(argv[i], stack_1, stack_2) < -2147483648)
		{
			ft_dprintf(2, "Error\n");
			exit_program(stack_1, stack_2, NULL);
		}
		i++;
	}
}

void	check_if_duplicate(int argc, char *argv[],
	t_stack *stack_1, t_stack *stack_2)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && my_atoi(argv[i], stack_1, stack_2)
				== my_atoi(argv[j], stack_1, stack_2))
			{
				ft_dprintf(2, "Error\n");
				exit_program(stack_1, stack_2, NULL);
			}
			j++;
		}
		i++;
	}
}

void	check_if_char(int argc, char *argv[],
	t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isalpha_edit(argv[i]))
		{
			ft_dprintf(2, "Error\n");
			exit_program(stack_1, stack_2, NULL);
		}
		i++;
	}
}

void	error_sign(int argc, char *argv[], t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') && argv[i][1] == '\0')
		{
			ft_dprintf(2, "Error\n");
			exit_program(stack_1, stack_2, NULL);
		}
		i++;
	}
}
