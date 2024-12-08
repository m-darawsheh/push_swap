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
	t_cost cost = {0, 0, 0, 0, 0, 0, 0};

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

	// printf("min: %d\n", min->data);

	cost.rotation = calc_rotation(node_len(b), find_index(b, min->data));
	cost.reverse_rotation = calc_reverse_rotation(node_len(b), find_index(b, min->data));

	cost.rotation_before_push = calc_rotation(node_len(a), find_index(a, node.data));
	cost.reverse_rotation_before_push = calc_reverse_rotation(node_len(a), find_index(a, node.data));

	cost.double_rotation = get_min_int(cost.rotation, cost.rotation_before_push);
	cost.double_reverse_rotation = get_min_int(cost.reverse_rotation, cost.reverse_rotation_before_push);

	// cost.rotation -= cost.double_rotation;
	// cost.rotation_before_push -= cost.double_rotation;
	// cost.reverse_rotation -= cost.double_reverse_rotation;
	// cost.reverse_rotation_before_push -= cost.double_reverse_rotation;
	cost.collective_cost = get_min_int(cost.rotation, cost.reverse_rotation) + get_min_int(cost.rotation_before_push, cost.reverse_rotation_before_push);

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

	printf("[cost] collective_cost: %d\n\n\n", cost.collective_cost);
}

void exe_cost(t_cost cost, t_node **a, t_node **b)
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

t_cost get_best_cost(t_node *a, t_node *b)
{
	t_node *a_node = a;
	t_cost cost_best = {-1, -1, -1, -1, -1, -1, -1};
	while (a_node)
	{
		// printf("node: %d\n", a_node->data);
		t_cost cost = calc_cost(*a_node, a, b);

		// print_cost(cost);

		if (cost_best.collective_cost == -1)
			cost_best = cost;

		if (cost.collective_cost < cost_best.collective_cost)
			cost_best = cost;

		// printf("node: %d\n", a_node->data);
		// print_cost(cost);
		a_node = a_node->next;
	}

	return (cost_best);
}

void	algo(t_node **a, t_node **b)
{
	// print_node(*a);
	// print_node(*b);



	push_to_node(a, b);
	push_to_node(a, b);
	// push_to_node(a, b);
	printf("pb\n");
	// printf("pb\n");
	printf("pb\n");

	// print_node(*a);
	// print_node(*b);
	// push_to_node(a, b);
	// printf("pb\n");
	// printf("pb\n");


	//  rotate_node(b);
	//  rotate_node(b);
	//  push_to_node(a, b);
	// printf("\n");
	// printf("\n");


	// printf("\n");

	t_node *temp;
	while ((temp = *a))
	{
		t_cost cost_best = get_best_cost(*a, *b);

		// printf("best cost: \n");
		// print_cost(cost_best);

		exe_cost(cost_best, a, b);

		// print_node(*a);
		// print_node(*b);

		push_to_node(a, b);
		printf("pb\n");
	}
	// print_node(*a);
	// print_node(*b);
	// printf("is_sorted %d\n", is_sorted(*b));

	t_node *max = get_max(*b);
	// printf("max: %d\n", max->data);

	int routations = calc_rotation(node_len(*b), find_index(*b, max->data));
	// printf("routations: %d\n", routations);
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
		// printf("node: %d\n", i->data);
	}

	// print_node(*a);



	// t_node *last_a;
	// while (last_a = get_last(*a))
	// {

	// 	t_node *best_rotation_a = last_a;
	// 	t_node *best_reverse_rotation_a = last_a;
	// 	int best_rotation = -1;
	// 	int best_reverse_rotation = -1;

	// 	while (last_a)
	// 	{
	// 		t_node *min = get_min(*b);
	// 		int min_index = find_index(*b, min->data);

	// 		int rotation = 0;
	// 		int reverse_rotation = 0;

	// 		t_node* temp = min;
	// 		while (last_a->data > min->data)
	// 		{
	// 			if (min->prev)
	// 				min = min->prev;
	// 			else
	// 				min = get_last(*b);

	// 			if (temp->data == min->data)
	// 				break;
	// 		}

	// 		rotation = calc_rotation(node_len(*b), find_index(*b, min->data));
	// 		reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, min->data));

	// 		printf("\ntesting for %d\n", last_a->data);
	// 		printf("min %d\n", min->data);
	// 		printf("rotation %d\n", rotation);
	// 		printf("reverse rotation %d\n", reverse_rotation);

	// 		if (best_rotation == -1)
	// 		{
	// 			best_rotation = rotation;
	// 			printf("best [r] !!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 		}

	// 		if (best_reverse_rotation == -1)
	// 		{
	// 			best_reverse_rotation = reverse_rotation;
	// 			printf("best [rr] !!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 		}

	// 		if (rotation < best_rotation)
	// 		{
	// 			printf("best [r] !!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 			best_rotation = rotation;
	// 			best_rotation_a = last_a;
	// 		}
	// 		if (reverse_rotation < best_reverse_rotation)
	// 		{
	// 			printf("best [rr] !!!!!!!!!!!!!!!!!!!!!!!!!\n");
	// 			best_reverse_rotation = reverse_rotation;
	// 			best_reverse_rotation_a = last_a;
	// 		}

	// 		last_a = last_a->prev;
	// 	}



		// t_node  *max = get_max(*b);

		// printf("min %d index: %d\n", min->data, min_index);


		// int generic_rotation;
		// if (rotation < reverse_rotation)
		// 	generic_rotation = rotation;
		// else
		// 	generic_rotation = reverse_rotation;

		// int j = 0;
		// while (j < generic_rotation)
		// {
		// 	if (rotation < reverse_rotation)
		// 	{
		// 		// printf("rb\n");
		// 		rotate_node(b);
		// 	}
		// 	else
		// 	{
		// 		// printf("rrb\n");
		// 		reverse_rotate_node(b);
		// 	}
		// 	j++;
		// }

		// push_to_node(a, b);
		// printf("pb\n");

		// print_node(*a);
		// print_node(*b);


		// printf("best r %d for number %d\n", best_rotation, best_rotation_a->data);
		// printf("best rr %d for number %d\n", best_reverse_rotation, best_reverse_rotation_a->data);

		// break;
	// }

	// print_node(*a);
	// print_node(*b);





	// push_to_node(a, b);

	// if (is_sorted(*b))
	//	 swap_last_two(b);

}


// -37 94 -12 58 -72 86 -45 3 -99 18 64 -41 77 -29 50 -25 92 -68 5 -81 21 -53 10 -32 66 -15 7 -47 97 -39 89 -1 74 -20 55 -33 98 -13 85 -56 31 -8 63 -46 17 -95 61 -36 73 -16 87 -11 60 -34 83 -70 48 -4 30 -26 62 -19 91 -24 44 -6 78 -42 2 -93 57 -38 28 -96 54 -75 35 -84 100 -40 22 -49 65 -14 88 -76 9 -27 82 -59 51 -79 67 -23 90 -71 52 -43 80 -69

// 2664
// 1839			-30%
// 474			-74%
