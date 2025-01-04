/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:39 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 10:20:57 by ataher           ###   ########.fr       */
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

void	check_if_max_min(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (my_strlen(argv[i]) > 10)
		{
			ft_printf("ERROR max or min!\n");
			exit(0);
		}
		if (my_atoi(argv[i]) > 2147483647 || my_atoi(argv[i]) < -2147483648)
		{
			ft_printf("ERROR max or min!\n");
			exit(0);
		}
		i++;
	}
}

void	check_if_duplicate(int argc, char *argv[])
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
				ft_printf("ERROR duplicate!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_if_char(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isalpha_edit(argv[i]))
		{
			ft_printf("ERROR char!\n");
			exit(0);
		}
		i++;
	}
}


void	error_sign(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') && argv[i][1] == '\0')
		{
			ft_printf("ERROR only sign!\n");
			exit(0);
		}
		i++;
	}
}
