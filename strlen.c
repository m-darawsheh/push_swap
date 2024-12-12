/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:30 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 16:12:55 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_push_a(t_node **b, t_node **a)
{
	push_to_node(b, a);
	push_to_node(b, a);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
}

void	double_push_b(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
}

size_t	my_strlen(char *str)
{
	size_t			i;
	bool			is_sign;

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
