/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:28 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 17:38:23 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"



void check_if_char(int argc, char *argv[])
{
    int i;
    i = 1;
    while (i < argc)
    {
        if (ft_isalpha_edit(argv[i]))
        {
            printf("ERROR char!\n");
            exit(0);
        }
        i++;
    }
}