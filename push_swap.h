/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/11/05 23:02:41 by hamzah           ###   ########.fr       */
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
	int				data;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

void	parse_arg(int argc, char *argv[], t_node **head);
long	my_atoi(const char *nptr);
void	ft_add_back(t_node **head, int data);
void	free_protection(t_node *node);
void	check_if_max_min(int argc, char *argv[]);
void	check_if_duplicate(int argc, char *argv[]);
void	check_if_char(int argc, char *argv[]);
int		ft_isalpha_edit(char *c);
bool	check_rubbish_sign(const char *nptr);
t_node	*ft_create_b(int argc);
size_t	my_strlen(char *str);
void	error_sign(int argc, char *argv[]);
void	swap_last_two(t_node **head);

#endif