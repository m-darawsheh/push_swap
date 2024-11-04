/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:08 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:45:56 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(const char *nptr)
{
	int	i;
	long	result;
	int	sign;
    bool is_rubbish;

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

