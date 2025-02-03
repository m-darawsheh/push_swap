/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/02/03 13:22:28 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>

# include "libft.h"
# include "libtrue.h"
# include "libftprintf.h"
# include "libgnl.h"

typedef struct s_cost
{
	int	r_to;
	int	r_from;
	int	rr_to;
	int	rr_from;
	int	rr;
	int	rrr;
	int	collective_cost_test1;
	int	collective_cost_test2;
	int	collective_cost_test3;
	int	collective_cost;
}	t_cost;

long	my_atoi(const char *nptr, t_stack *stack_1, t_stack *stack_2);
int		ft_isalpha_edit(char *c);
size_t	my_strlen(char *str);
void	parse_arg(int argc, char *argv[], t_stack *stack_1, t_stack *stack_2);
void	check_if_max_min(int argc, char *argv[],
			t_stack *stack_1, t_stack *stack_2);
void	check_if_duplicate(int argc, char *argv[],
			t_stack *stack_1, t_stack *stack_2);
void	check_if_char(int argc, char *argv[],
			t_stack *stack_1, t_stack *stack_2);
void	error_sign(int argc, char *argv[], t_stack *stack_1, t_stack *stack_2);
bool	check_rubbish_sign(const char *nptr);
int		is_sorted(t_stack stack);
void	exit_program(t_stack *a, t_stack *b, void *ptr);

t_node	*get_min(t_stack stack);
int		calc_rotation(int length, int index);
int		calc_reverse_rotation(int length, int index);
int		get_min_int(int a, int b);
t_node	*get_postion(t_node node, t_stack *stack_1, t_stack *stack_2);

void	exe_cost(t_cost cost, t_stack *stack_1, t_stack *stack_2);
t_cost	get_best_cost(t_stack *stack_1, t_stack *stack_2);
int		is_sorted(t_stack stack);

void	sort_less_then_three(t_stack *stack);
void	shift_sort_stack(t_stack *stack);
void	stack_push_to(t_stack *stack_1, t_stack *stack_2);
int		is_sorted(t_stack stack);

#endif
