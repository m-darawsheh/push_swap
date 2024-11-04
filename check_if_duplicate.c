/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:33 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 17:30:10 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void check_if_duplicate(int argc, char *argv[])
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 1;
        while (j < argc)
        {
            if (i != j && my_atoi(argv[i]) == my_atoi(argv[j]))
            {
                printf("ERROR duplicate!\n");
                exit(0);
            }
            j++;
        }
        i++;
    }

}