/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 12:03:14 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

# include "libft/libft.h"
# include "libft/ft_printf/include/ft_printf.h"
# include "libtrue/include/true_linked_list.h"

// typedef struct t_node
// {
// 	int				data;
// 	struct t_node	*next;
// 	struct t_node	*prev;
// }	t_node;

// void	parse_arg(int argc, char *argv[], t_node **head);
long	my_atoi(const char *nptr);
// void	ft_add_back(t_node **head, int data);
// void	ft_add_front(t_node **head, int data);

// void	free_protection(t_node *node);
int		ft_isalpha_edit(char *c);
size_t	my_strlen(char *str);

// void	print_node(t_node *node);

// void	push_to_node(t_node **head,t_node **b);

// void	reverse_rotate_node(t_node **node);
// void	rotate_node(t_node **a);
// bool	is_sorted(t_node *node);

// void    algo(t_node **a, t_node **b);
// int		find_index(t_node *node, int data);
// int	node_len(t_node *node);

// t_node *get_min(t_node *stack);
// t_node *get_last(t_node *stack);
void	parse_arg(int argc, char *argv[], t_stack *stack);

void	check_if_max_min(int argc, char *argv[]);
void	check_if_duplicate(int argc, char *argv[]);
void	check_if_char(int argc, char *argv[]);
void	error_sign(int argc, char *argv[]);
bool	check_rubbish_sign(const char *nptr);

void	algo(t_stack *a, t_stack *b);


#endif
