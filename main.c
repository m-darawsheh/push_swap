/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:44:23 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"


int main (int   argc, char    **argv)
{
    t_node *head = NULL;
    // t_node *b;
    if (argc < 3)
        return (0);  
    parse_arg(argc, argv, &head);
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("SUCCESS!\n");
}
