/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:24:01 by mdarawsh          #+#    #+#             */
/*   Updated: 2024/12/11 14:45:25 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

