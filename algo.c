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

		t_node *temp = min;
		while (a->data > min->data)
		{
			if (min->prev)
				min = min->prev;
			else
				min = get_last(b);

			if (temp->data == min->data)
			{
				// printf("minimum is %d\n", min->data);
				return (min->data);
			}
		}
		return (min->data);
}


t_node *winner_node(t_node *a, t_node *b)
{
    t_node *winner = NULL;
    t_node *temp = get_last(a);
    int min_opration = INT_MAX;

    while (temp)
    {
		// printf("the data which will be checked is %d\n", temp->data);

		int data = right_place(temp, b);

		int rotation = 0;
		int reverse_rotation = 0;

		int rotation_a = 0;
		int reverse_rotation_a = 0;

		rotation = calc_rotation(node_len(b), find_index(b, data));
		reverse_rotation = calc_reverse_rotation(node_len(b), find_index(b, data));
        int for_right_place = rotation<reverse_rotation ? rotation : reverse_rotation;
		
		rotation_a = calc_rotation(node_len(a), find_index(a, temp->data));
		reverse_rotation_a = calc_reverse_rotation(node_len(a), find_index(a, temp->data));
		int for_top = rotation_a<reverse_rotation_a ? rotation_a : reverse_rotation_a;
        int total = for_top + for_right_place;

        if (total < min_opration)
        {	
			// printf("for top is %d\t for right place is %d\n", for_top, for_right_place);
			// printf("the total is %d\n", total);
            min_opration = total;
            winner = temp;
        }

		temp = temp->prev;
    }
	// printf ("the winner is %d\n", winner->data);

    return (winner);
}
bool	three_in_a(t_node *stack)
{
	int i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	if (i == 3)
		return (true);
	return (false);
}
bool the_list_is_empty(t_node *stack)
{
	if (!stack)
		return (true);
	return (false);
}

bool	is_sorted_a(t_node *node)
{
	t_node *temp = node;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			{
				printf("the list is not sorted\n");
				return (false);
			}
		temp = temp->next;
	}
	printf("the list is sorted\n");
	return (true);
}

void	algo(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	printf("pb\n");
	printf("pb\n");



	bool	stop = false;
	while (!stop)
	{
		t_node *winner = winner_node(*a, *b);
		// printf("winner is %d\t", winner->data);
		// printf("index is %d\n", find_index(*a, winner->data));
		int Data = right_place(winner, *b);
		int rotation = 0;
		int reverse_rotation = 0;

		rotation = calc_rotation(node_len(*b), find_index(*b, Data));
		reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, Data));

		int r_to_top = calc_rotation(node_len(*a), find_index(*a, winner->data));
		int rr_to_top = calc_reverse_rotation(node_len(*a), find_index(*a, winner->data));
		// int for_top = r_to_top < rr_to_top ? r_to_top : rr_to_top;
		int for_top = 0;
		bool is_ra = true;
		if (r_to_top < rr_to_top)
		{
			for_top = r_to_top;
		}
		else
		{
			for_top = rr_to_top;
			is_ra = false;
		}
		bool is_rb = true;
		// int for_right_place = rotation<reverse_rotation ? rotation : reverse_rotation;
		int for_right_place = 0;

		if (rotation < reverse_rotation)
		{
			for_right_place = rotation;
		}
		else
		{
			for_right_place = reverse_rotation;
			is_rb = false;
		}



		// print_node(*a);
		// print_node(*b);
		// int limiting_factor = 0;
		// if 

		int i = 0;
		while (i < for_top)
		{
			if (is_ra)
			{
				rotate_node(a);
				printf("ra\n");
			}
			else
			{
				reverse_rotate_node(a);
				printf("rra\n");

			}
			i++;
		}
		int j = 0;

		while (j < for_right_place)
		{
			if(is_rb)
			{
				rotate_node(b);
				printf("rb\n");
			}
			else
			{
				reverse_rotate_node(b);
				printf("rrb\n");
			}
			j++;
		}
		push_to_node(a, b);
		printf("pb\n");

		stop = the_list_is_empty(*a);
		


	}
	// print_node(*b);

	t_node *min = get_min(*b);

	int rotation_min = calc_rotation(node_len(*b), find_index(*b, min->data));

	int reverse_rotation_min = calc_reverse_rotation(node_len(*b), find_index(*b, min->data));
	int min_to_top = rotation_min<reverse_rotation_min ? rotation_min : reverse_rotation_min;
	int i = 0;
	while (i < min_to_top)
	{
		if (rotation_min < reverse_rotation_min)
		{
			rotate_node(b);
			printf("rb\n");
		}
		else
		{
			reverse_rotate_node(b);
			printf("rrb\n");
		}
		i++;
	}
	int push_count = node_len (*b);
	i = 0;
	while (i < push_count)
	{
		push_to_node(b, a);
		printf("pa\n");
		i++;
	}
	// print_node(*a);
	// is_sorted_a(*a);

}



