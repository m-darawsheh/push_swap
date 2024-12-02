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
	return length - index - 1;
}

int calc_reverse_rotation(int length, int index)
{
	return (index + 1);
}

int HowManyRotation_to_top(t_node *stack, int data)
{
	int index;
	int rotation;

	index = find_index(stack, data);
	rotation = calc_rotation(node_len(stack), index);
	return (rotation);
}
int HowManyReverseRotation_to_top(t_node *stack, int data)
{
	int index;
	int reverse_rotation;

	index = find_index(stack, data);
	reverse_rotation = calc_reverse_rotation(node_len(stack), index);
	return (reverse_rotation);
}







int	right_place(t_node *a, t_node *b)
{

		t_node *min = get_min(b);
		// int min_index = find_index(b, min->data);

		t_node *temp = min;
		while (a->data > min->data)
		{
			if (min->prev)
				min = min->prev;
			else
				min = get_last(b);

			if (temp->data == min->data)
				return (min->data);
		}
		return (min->data);
}

void	algo(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	printf("pb\n");
	printf("pb\n");




	t_node *last_a;
	while (last_a = get_last(*a))
	{
		// must here call the khalele and choose the rotation or reverse rotation
		// do not forget to edite on khalele and the next step is suring if i walk on 
		// every single element in a and calculate how many rotation or reverse rotation
		// need it to be on the right place

		int data = right_place(last_a, *b);

		int rotation = 0;
		int reverse_rotation = 0;

		rotation = calc_rotation(node_len(*b), find_index(*b, data));
		reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, data));

		bool	do_rotate_b = true;
		t_node *winer_node = last_a;
		int min_opration ;
		if (rotation < reverse_rotation)
		{
			min_opration = rotation;
		}
		else
		{
			min_opration = reverse_rotation;
			do_rotate_b = false;
		}
		int	for_top = 0;
		bool	do_rotate_a = true;

		while(true)
		{
			int	index = find_index(*a, winer_node->data) + 1;
			float	middle = node_len(*a) / 2;
			if (index < middle)
			{
				for_top = HowManyReverseRotation_to_top(*a, winer_node->data);
				do_rotate_a = false;
			}
			else
			{
				for_top = HowManyRotation_to_top(*a, winer_node->data);
			}
			int	data = right_place(winer_node, *b);
			int	for_right_place;
			rotation = calc_rotation(node_len(*b), find_index(*b, data));
			reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, data));
			if (rotation < reverse_rotation)
			{
				for_right_place = rotation;
			}
			else
			{
				for_right_place = reverse_rotation;
				do_rotate_b = false;
			}

			int	total = for_top + for_right_place;
			if (total < min_opration)
			{
				min_opration = total;
			}

			winer_node = winer_node->prev;
			if (!winer_node)
				break;
		}


		int generic_rotation;
		if (do_rotate_b)
			generic_rotation = rotation;
			
		else
			generic_rotation = reverse_rotation;




		int	rx = 0;
		while (rx < for_top)
		{
			if (do_rotate_a)
			{
				rotate_node(a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate_node(a);
				printf("rra\n");
			}
			rx++;
		}
		

		int j = 0;
		while (j < generic_rotation)
		{
			if (rotation < reverse_rotation)
			{
				printf("rb\n");
				rotate_node(b);
			}
			else
			{
				printf("rrb\n");
				reverse_rotate_node(b);
			}
			j++;
		}

		push_to_node(a, b);
		printf("pb\n");

	}
	 
	print_node(*b);

	printf( is_sorted(*b) ? "is sorted\n" : "not sorted\n");

}
           

// -37 94 -12 58 -72 86 -45 3 -99 18 64 -41 77 -29 50 -25 92 -68 5 -81 21 -53 10 -32 66 -15 7 -47 97 -39 89 -1 74 -20 55 -33 98 -13 85 -56 31 -8 63 -46 17 -95 61 -36 73 -16 87 -11 60 -34 83 -70 48 -4 30 -26 62 -19 91 -24 44 -6 78 -42 2 -93 57 -38 28 -96 54 -75 35 -84 100 -40 22 -49 65 -14 88 -76 9 -27 82 -59 51 -79 67 -23 90 -71 52 -43 80 -69

// 2665

// t_node  *get_max(t_node *stack)
// {
//	 t_node  *max = stack;
//	 while (stack)
//	 {
//		 if (stack->data > max->data)
//			 max = stack;
//		 stack = stack->next;
//	 }
// }

//	 push_to_node(a, b);
	// print_node(*a);
		// printf("min %d index: %d\n", min->data, min_index);

		// t_node  *max = get_max(*b);
		// printf("min %d\n", min->data);
		// printf("rotation %d\n", rotation);
		// printf("reverse rotation %d\n", reverse_rotation);
	// print_node(*b);
	// print_node(*a);
	// print_node(*a);
	// print_node(*b);

	// push_to_node(a, b);

	// if (is_sorted(*b))
	//	 swap_last_two(b);

	// push_to_node(a, b);