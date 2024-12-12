/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/12 15:38:42 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	struct t_node	*next;
	struct t_node	*prev;
}	t_node;

typedef struct t_number
{
	int				total;
	int				rotation;
	int				reverse_rotation;
	int				rotation_a;
	int				reverse_rotation_a;
	int				for_top;
	int				for_right_place;
}	t_number;

void		ft_add_front(t_node **head, int data);
void		parse_arg(int argc, char *argv[], t_node **head);
long		my_atoi(const char *nptr);
void		ft_add_back(t_node **head, int data);
void		free_protection(t_node **head);
void		check_if_max_min(int argc, char *argv[], t_node **head);
void		check_if_duplicate(int argc, char *argv[], t_node **head);
void		check_if_char(int argc, char *argv[], t_node **head);
int			ft_isalpha_edit(char *c);
void		error_sign(int argc, char *argv[], t_node **head);
void		swap_last_two(t_node **head);
void		print_node(t_node *node);
void		delete_first_node(t_node	**node);
void		push_to_node(t_node **head, t_node **b);
void		reverse_rotate_node(t_node **node);
void		rotate_node(t_node **a);
void		ss(t_node **a, t_node **b);
void		rr(t_node **a, t_node **b);
void		rrr(t_node **a, t_node **b);
int			find_min_data(t_node *node);
int			find_max_data(t_node *node);
bool		is_sorted(t_node *node);
bool		is_sorted_a(t_node *node);
void		algo(t_node **a, t_node **b);
int			find_index(t_node *node, int data);
int			node_len(t_node *node);
int			calc_rotation(int length, int index);
int			calc_rr(int length, int index);
int			right_place(t_node	*a, t_node	*b);
bool		the_list_is_empty(t_node *stack);
bool		is_sorted_a(t_node *node);
void		algo(t_node **a, t_node **b);
int			find_numberes(t_node *temp, t_node *a, t_node *b, int data);
void		do_rotations_a(t_number x, t_node **a);
void		do_rotations_b(t_number x, t_node **b);
void		make_b_inverse(t_node **b);
void		pushing(t_node **b, t_node **a);
size_t		my_strlen(char *str);
t_node		*winner_node(t_node *a, t_node *b);
t_node		*get_min(t_node *stack);
t_node		*get_max(t_node *stack);
t_node		*get_last(t_node *stack);
t_number	find_rights(t_node *temp, t_node *a, t_node	*b, int data);
void		check_first_two(t_node **a);
void		s_kh(t_node **a);
void		m_dr(t_node **a, t_node **b);
void		push_min(t_node **a, t_node **b, t_node *min);
void		push_max(t_node **a, t_node **b, t_node *max);
void		double_rra(t_node **a);
void		double_ra(t_node **a);
void		double_push_a(t_node **b, t_node **a);
void		double_push_b(t_node **a, t_node **b);
#endif
