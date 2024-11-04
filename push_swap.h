/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/04 18:43:39 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct t_node
{
	int data;
	struct t_node *next;
	struct t_node *prev;
} t_node;

void	parse_arg(int argc, char *argv[], t_node **head);
long	my_atoi(const char *nptr);
t_node *ft_create_b(int argc);
void ft_add_back(t_node **head, int data);
void free_protiction(t_node *node);
bool check_rubbish_sign(const char *nptr);
void check_if_max_min(int argc, char *argv[]);
void check_if_duplicate(int argc, char *argv[]);
void check_if_char(int argc, char *argv[]);
int	ft_isalpha_edit(char *c);
size_t	my_strlen(char *str);

#endif