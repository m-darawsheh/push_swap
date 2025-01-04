/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:19:26 by ataher            #+#    #+#             */
/*   Updated: 2025/01/04 10:20:57 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a = stack_init();
	t_stack b = stack_init();

	parse_arg(argc, argv, &a);

	// a.log.simple(a);
	// b.log.simple(b);

	algo(&a, &b);

	// a.log.simple(a);
	// b.log.simple(b);

	a.clear(&a);
	b.clear(&b);
	return (0);
}

