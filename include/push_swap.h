/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:10 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/01/04 10:17:20 by ataher           ###   ########.fr       */
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
