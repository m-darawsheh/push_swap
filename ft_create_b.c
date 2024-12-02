/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:53 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/02 09:56:42 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node	*ft_create_b(int argc)
{
	t_node	*b;

	b = malloc (argc * sizeof(t_node));
	if (!b)
		free_protection(b);
	return (b);
}