/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:18:35 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 10:20:44 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	my_strlen(char *str)
{
	size_t	i;
	bool is_sign;

	is_sign = false;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		is_sign = true;
	}
	while (str[i] != '\0')
		i++;

	if (is_sign)
	{
		return (i - 1);
	}
	return (i);
}
