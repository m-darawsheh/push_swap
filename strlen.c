/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/06 11:11:56 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	my_strlen(char *str)
{
	size_t	i;
	bool is_sign;
	
	is_sign; = false;
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
