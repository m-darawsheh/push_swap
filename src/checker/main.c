/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:38:09 by ataher            #+#    #+#             */
/*   Updated: 2025/01/22 01:37:56 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_stack_checker(t_stack *stack)
{
	int	temp;

	temp = stack->head->content;
	stack->head->content = stack->head->next->content;
	stack->head->next->content = temp;
}

void	stack_push_to_checker(t_stack *stack_1, t_stack *stack_2)
{
	stack_2->insert(stack_2, node_dup(stack_1->head), 0);
	stack_1->pop(stack_1, 0);
}

void	execution(t_stack *a, t_stack *b, char *opporation)
{
	if (ft_strcmp(opporation, "pb\n") == 0)
		stack_push_to_checker(a, b);
	if (ft_strcmp(opporation, "pa\n") == 0)
		stack_push_to_checker(b, a);
	if (ft_strcmp(opporation, "sa\n") == 0 || ft_strcmp(opporation, "ss\n") == 0)
		swap_stack_checker(a);
	if (ft_strcmp(opporation, "sb\n") == 0 || ft_strcmp(opporation, "ss\n") == 0)
		swap_stack_checker(b);
	if (ft_strcmp(opporation, "ra\n") == 0 || ft_strcmp(opporation, "rr\n") == 0)
		a->shift(a, -1);
	if (ft_strcmp(opporation, "rb\n") == 0 || ft_strcmp(opporation, "rr\n") == 0)
		b->shift(b, -1);
	if (ft_strcmp(opporation, "rra\n") == 0
		|| ft_strcmp(opporation, "rrr\n") == 0)
		a->shift(a, 1);
	if (ft_strcmp(opporation, "rrb\n") == 0
		|| ft_strcmp(opporation, "rrr\n") == 0)
		b->shift(b, 1);
	free(opporation);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = stack_init('a');
	b = stack_init('b');
	if (!a || !b)
		exit_program(a, b, NULL);
	parse_arg(argc, argv, a, b);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execution(a, b, line);
	}
	if (is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	a->clear(a);
	b->clear(b);
	return (0);
}
