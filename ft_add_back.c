/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:50 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 17:30:30 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void ft_add_back(t_node **head, int data)
{
    t_node *new;
    t_node *temp;
    new = malloc(sizeof(t_node));
    if (!new)
        free_protiction(*head);
    new->data = data;
    new->next = NULL;
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}