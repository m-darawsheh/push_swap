/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_edit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:38:27 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:55:03 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha_edit(char *c)
{
    int i;
    i = 0;
    while (c[i])
    {
        if ( c[i] > '9' && c[i] < '0'
            && c[i] != '+' && c[i] != '-')
            return (1);
        i++;
    }
    return (0);
}