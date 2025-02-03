/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:49:51 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 17:01:18 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_program(t_stack *a, t_stack *b, void *ptr)
{
	if (a)
		a->clear(a);
	if (b)
		b->clear(b);
	if (ptr)
		free(ptr);
	exit(1);
}
