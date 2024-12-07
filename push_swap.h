/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/02 09:57:15 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>

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
void	error_sign(int argc, char *argv[]);
void	swap_last_two(t_node **head);
void	print_node(t_node *node);
void	delete_last_node(t_node **node);
void	push_to_node(t_node **head,t_node **b);
void	reverse_rotate_node(t_node **node);
void	rotate_node(t_node **a);
void	ss(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);
int		find_min_data(t_node *node);
int		find_max_data(t_node *node);
bool	is_sorted(t_node *node);
bool	is_sorted_a(t_node *node);
void	algo(t_node **a, t_node **b);
int		last_data(t_node *node);
int		find_index(t_node *node, int data);
int		node_len(t_node *node);
size_t	my_strlen(char *str); 
t_node	*get_min(t_node *stack);
t_node	*get_last(t_node *stack);
#endif
