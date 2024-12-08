#include "push_swap.h"

t_node *get_min(t_node *stack)
{
	t_node *min = stack;

	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}

	return (min);
}

t_node  *get_max(t_node *stack)
{
	t_node *max = stack;

	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}

	return (max);
}

t_node *get_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

t_cost calc_cost(t_node node, t_node *a, t_node *b)
{
	t_cost cost = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	t_node *min = get_min(b);
	t_node* temp = min;
	while (node.data > min->data)
	{
		if (min->prev)
			min = min->prev;
		else
			min = get_last(b);

		if (temp->data == min->data)
			break;
	}
	if(min->next)
		min = min->next;
	else
		min = b;

	cost.rotation = calc_rotation(node_len(b), find_index(b, min->data));
	cost.reverse_rotation = calc_reverse_rotation(node_len(b), find_index(b, min->data));

	cost.rotation_before_push = calc_rotation(node_len(a), find_index(a, node.data));
	cost.reverse_rotation_before_push = calc_reverse_rotation(node_len(a), find_index(a, node.data));

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
	printf("[a] rotation: %d\n", cost.rotation_before_push);
	printf("[a] reverse_rotation: %d\n", cost.reverse_rotation_before_push);

	printf("[b] rotation: %d\n", cost.rotation);
	printf("[b] reverse_rotation: %d\n", cost.reverse_rotation);

	printf("[ab] rotation: %d\n", cost.double_rotation);
	printf("[ab] reverse_rotation: %d\n", cost.double_reverse_rotation);

	printf("[cost] collective_cost_test1: %d\n", cost.collective_cost_test1);
	printf("[cost] collective_cost_test2: %d\n", cost.collective_cost_test2);
	printf("[cost] collective_cost_test3: %d\n", cost.collective_cost_test3);
	printf("[cost] collective_cost: %d\n\n\n", cost.collective_cost);
}

void exe_cost(t_cost cost, t_node **a, t_node **b)
{
	if (cost.collective_cost == cost.collective_cost_test1)
	{
		if (cost.rotation_before_push < cost.reverse_rotation_before_push)
			while (cost.rotation_before_push--)
			{
				rotate_node(a);
				printf("ra\n");
			}
		else
			while (cost.reverse_rotation_before_push--)
			{
				reverse_rotate_node(a);
				printf("rra\n");
			}
		if (cost.rotation < cost.reverse_rotation)
			while (cost.rotation--)
			{
				rotate_node(b);
				printf("rb\n");
			}
		else
			while (cost.reverse_rotation--)
			{
				reverse_rotate_node(b);
				printf("rrb\n");
			}
	}
	else if (cost.collective_cost == cost.collective_cost_test2)
	{
		while (cost.double_rotation--)
		{
			rotate_node(a);
			rotate_node(b);
			printf("rr\n");
			cost.rotation -= 1;
			cost.rotation_before_push -= 1;
		}
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, a, b);
	}
	else if (cost.collective_cost == cost.collective_cost_test3)
	{
		while (cost.double_reverse_rotation--)
		{
			reverse_rotate_node(a);
			reverse_rotate_node(b);
			printf("rrr\n");
			cost.reverse_rotation -= 1;
			cost.reverse_rotation_before_push -= 1;
		}
		cost.collective_cost = cost.collective_cost_test1;
		exe_cost(cost, a, b);
	}
}

t_cost get_best_cost(t_node *a, t_node *b)
{
	t_node *a_node = a;
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

void	algo(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	printf("pb\n");
	printf("pb\n");
	t_node *temp;
	while ((temp = *a))
	{
		t_cost cost_best = get_best_cost(*a, *b);
		exe_cost(cost_best, a, b);
		push_to_node(a, b);
		printf("pb\n");
	}
	t_node *max = get_max(*b);
	int routations = calc_rotation(node_len(*b), find_index(*b, max->data));
	while (routations--)
	{
		rotate_node(b);
		printf("rb\n");
	}
	t_node *i;
	while ((i = *b))
	{
		printf("pa\n");
		push_to_node(b, a);
	}
}
