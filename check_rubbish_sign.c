/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rubbish_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:41 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:44:11 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

bool check_rubbish_sign(const char *nptr)
{
    int i;

    i = 0;
    if (nptr[i] == '-' || nptr[i] == '+')
        i++;
    while (nptr[i])
    {
        if (nptr[i] == '-' || nptr[i] == '+')
        {
            return (true);
        }
        i++;
    }
    return (false);
}
