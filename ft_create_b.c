/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:53 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/05 22:53:23 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_b(int argc)
{
	t_node	*b;

	b = calloc (argc, sizeof(t_node));
	if (!b)
		free_protiction(b);
	return (b);
}
