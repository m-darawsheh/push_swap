#include "push_swap.h"

t_node *get_min(t_stack stack)
{
	t_node *min = stack.head;

	while (stack.head)
	{
		if (stack.head->content < min->content)
			min = stack.head;
		stack.head = stack.head->next;
	}

	return (min);
}

t_node *get_max(t_stack stack)
{
	t_node *max = stack.head;

	while (stack.head)
	{
		if (stack.head->content > max->content)
			max = stack.head;
		stack.head = stack.head->next;
	}

	return (max);
}

// t_node  *get_max(t_node *stack)
// {
// 	t_node *max = stack;

// 	while (stack)
// 	{
// 		if (stack->data > max->data)
// 			max = stack;
// 		stack = stack->next;
// 	}

// 	return (max);
// }

// t_node *get_last(t_node *stack)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next)
// 		stack = stack->next;
// 	return (stack);
// }

int calc_rotation(int length, int index)
{
	(void)length;
	return index;
}

int calc_reverse_rotation(int length, int index)
{
	return index == 0 ? 0 : length - index;
}

typedef struct s_cost
{
	int rotation;
	int reverse_rotation;
	int rotation_before_push;
	int reverse_rotation_before_push;

	int double_rotation;
	int double_reverse_rotation;

	int collective_cost_test1;
	int collective_cost_test2;
	int collective_cost_test3;
	int collective_cost;
} t_cost;

int get_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		find_index(t_stack stack, int content)
{
	int	i;

	i = 0;
	while (stack.head)
	{
		if (stack.head->content == content)
			return (i);
		stack.head = stack.head->next;
		i++;
	}
	ft_printf( "error input data\n");
	return (-1);
}

t_cost calc_cost(t_node node, t_stack *a, t_stack *b)
{
	t_cost cost = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_node *min = get_min(*b);
	t_node* temp = min;
	while (node.content > min->content)
	{
		if (min->prev)
			min = min->prev;
		else
			min = b->tail;

		if (temp->content == min->content)
			break;
	}
	if(min->next)
		min = min->next;
	else
		min = b->head;

	cost.rotation = calc_rotation(b->size, find_index(*b, min->content));
	cost.reverse_rotation = calc_reverse_rotation(b->size, find_index(*b, min->content));

	cost.rotation_before_push = calc_rotation(a->size, find_index(*a, node.content));
	cost.reverse_rotation_before_push = calc_reverse_rotation(a->size, find_index(*a, node.content));

	cost.double_rotation = get_min_int(cost.rotation, cost.rotation_before_push);
	cost.double_reverse_rotation = get_min_int(cost.reverse_rotation, cost.reverse_rotation_before_push);

	cost.collective_cost_test1 = get_min_int(cost.rotation, cost.reverse_rotation) + get_min_int(cost.rotation_before_push, cost.reverse_rotation_before_push);
	cost.collective_cost_test2 = cost.double_rotation + (cost.rotation - cost.double_rotation) + (cost.rotation_before_push - cost.double_rotation);
	cost.collective_cost_test3 = cost.double_reverse_rotation + (cost.reverse_rotation - cost.double_reverse_rotation) + (cost.reverse_rotation_before_push - cost.double_reverse_rotation);
	cost.collective_cost = get_min_int(cost.collective_cost_test1, get_min_int(cost.collective_cost_test2, cost.collective_cost_test3));
	return (cost);
}

void print_cost(t_cost cost)
{
	ft_printf("[a] rotation: %d\n", cost.rotation_before_push);
	ft_printf("[a] reverse_rotation: %d\n", cost.reverse_rotation_before_push);

	ft_printf("[b] rotation: %d\n", cost.rotation);
	ft_printf("[b] reverse_rotation: %d\n", cost.reverse_rotation);

	ft_printf("[ab] rotation: %d\n", cost.double_rotation);
	ft_printf("[ab] reverse_rotation: %d\n", cost.double_reverse_rotation);

	ft_printf("[cost] collective_cost_test1: %d\n", cost.collective_cost_test1);
	ft_printf("[cost] collective_cost_test2: %d\n", cost.collective_cost_test2);
	ft_printf("[cost] collective_cost_test3: %d\n", cost.collective_cost_test3);
	ft_printf("[cost] collective_cost: %d\n\n\n", cost.collective_cost);
}

void exe_cost(t_cost cost, t_stack *a, t_stack *b)
{
	if (cost.collective_cost == cost.collective_cost_test1)
	{
		if (cost.rotation_before_push < cost.reverse_rotation_before_push)
		{
			a->shift(a, -cost.rotation_before_push);
			while (cost.rotation_before_push--)
				ft_printf("ra\n");
		}
		else
		{
			a->shift(a, cost.reverse_rotation_before_push);
			while (cost.reverse_rotation_before_push--)
				ft_printf("rra\n");
		}
		if (cost.rotation < cost.reverse_rotation)
		{
			b->shift(b, -cost.rotation);
			while (cost.rotation--)
				ft_printf("rb\n");
		}
		else
		{
			b->shift(b, cost.reverse_rotation);
			while (cost.reverse_rotation--)
				ft_printf("rrb\n");
		}
	}
	else if (cost.collective_cost == cost.collective_cost_test2)
	{
		a->shift(a, -cost.double_rotation);
		b->shift(b, -cost.double_rotation);
		cost.rotation -= cost.double_rotation;
		cost.rotation_before_push -= cost.double_rotation;
		while (cost.double_rotation--)
			ft_printf("rr\n");
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, a, b);
	}
	else if (cost.collective_cost == cost.collective_cost_test3)
	{
		a->shift(a, cost.double_reverse_rotation);
		b->shift(b, cost.double_reverse_rotation);
		cost.reverse_rotation -= cost.double_reverse_rotation;
		cost.reverse_rotation_before_push -= cost.double_reverse_rotation;
		while (cost.double_reverse_rotation--)
			ft_printf("rrr\n");
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, a, b);
	}
}

t_cost get_best_cost(t_stack *a, t_stack *b)
{
	t_node *a_node = a->head;
	t_cost cost_best = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	while (a_node)
	{
		t_cost cost = calc_cost(*a_node, a, b);
		if (cost_best.collective_cost == -1)
			cost_best = cost;
		if (cost.collective_cost < cost_best.collective_cost)
			cost_best = cost;
		a_node = a_node->next;
	}
	return (cost_best);
}

void	algo(t_stack *a, t_stack *b)
{
	b->insert(b, node_dup(a->head), 0);
	a->pop(a, 0);
	b->insert(b, node_dup(a->head), 0);
	a->pop(a, 0);
	ft_printf("pb\n");
	ft_printf("pb\n");

	t_node *temp;
	while ((temp = a->head))
	{
		t_cost cost_best = get_best_cost(a, b);
		exe_cost(cost_best, a, b);


		// a->log.simple(*a);
		// b->log.simple(*b);

		// ft_printf("temp: %d\n", temp->content);

		b->insert(b, node_dup(a->head), 0);
		a->pop(a, 0);
		ft_printf("pb\n");
	}

	// a->log.simple(*a);
	// b->log.simple(*b);

	// a->pop(a, 0);

	t_node *max = get_max(*b);
	int routations = calc_rotation(b->size, find_index(*b, max->content));
	while (routations--)
	{
		b->shift(b, -1);
		ft_printf("rb\n");
	}
	t_node *i;
	while ((i = b->head))
	{
		ft_printf("pa\n");
		a->insert(a, node_dup(b->head), 0);
		b->pop(b, 0);
	}

	// a->log.simple(*a);
	// b->log.simple(*b);
}
