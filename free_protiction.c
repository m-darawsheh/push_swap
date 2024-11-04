/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_protiction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:46 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 17:29:46 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void free_protiction(t_node *node)
{
    t_node *temp;
    while (node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
    exit(0);
}

