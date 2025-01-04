/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:20 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 10:20:57 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
