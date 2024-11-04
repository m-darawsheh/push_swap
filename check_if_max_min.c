/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_max_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:37 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:43:53 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void check_if_max_min(int argc, char *argv[])
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (my_strlen(argv[i]) > 10)
        {
            printf("ERROR max or min!\n");
            exit(0);
        }
        if (my_atoi(argv[i]) > 2147483647 || my_atoi(argv[i]) < -2147483648)
        {
            printf("ERROR max or min!\n");
            exit(0);
        }
        i++;
    }
}
