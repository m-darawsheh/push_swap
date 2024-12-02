/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:41 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:46 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			printf("ERROR max or min!\n");
			exit(0);
		}
		if (my_atoi(argv[i]) > 2147483647 || my_atoi(argv[i]) < -2147483648)
		{
			printf("ERROR max or min!\n");
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
				printf("ERROR duplicate!\n");
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
			printf("ERROR char!\n");
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
			printf("ERROR only sign!\n");
			exit(0);
		}
		i++;	
	}
}