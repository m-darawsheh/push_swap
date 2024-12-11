/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 14:42:19 by ataher           ###   ########.fr       */
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

long	my_atoi(const char *nptr);

int		ft_isalpha_edit(char *c);
size_t	my_strlen(char *str);

void	parse_arg(int argc, char *argv[], t_stack *stack);

void	check_if_max_min(int argc, char *argv[]);
void	check_if_duplicate(int argc, char *argv[]);
void	check_if_char(int argc, char *argv[]);
void	error_sign(int argc, char *argv[]);
bool	check_rubbish_sign(const char *nptr);

void	algo(t_stack *a, t_stack *b);


#endif
