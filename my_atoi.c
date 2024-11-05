/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:08 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/05 22:49:30 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;
	bool	is_rubbish;

	i = 0;
	sign = 1;
	result = 0;
	is_rubbish = false;
	is_rubbish = check_rubbish_sign(nptr);
	if (is_rubbish)
	{
		printf("ERROR rubbish sign!\n");
		exit(0);
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
