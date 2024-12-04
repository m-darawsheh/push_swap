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

bool	be_rotated(t_node *node)
{

	int len = node_len(node);
	int index = find_index(node, node->data) + 1;
	int mid;
	float mid_float;

	mid = len / 2;
	mid_float = len / 2;
	if (mid_float > mid)
	{
		mid++;
	}

	if (index <= mid)
		return (false);
	else
		return (true);
	// bool	is_rotated = true;
	// float	local = (float)find_index(node, node->data) + 1.00;
	// float	length =(float)node_len(node);
	// float	middle = length / 2;

	// if (local <= middle)
	// 	is_rotated = false;
	// return (is_rotated);
}

t_node *winner_node(t_node *a, t_node *b)
{
    t_node *winner = NULL;
    t_node *temp = get_last(a);
    int min_opration = INT_MAX;

    while (temp)
    {

		int data = right_place(temp, b);

		int rotation = 0;
		int reverse_rotation = 0;

		rotation = calc_rotation(node_len(b), find_index(b, data));
		reverse_rotation = calc_reverse_rotation(node_len(b), find_index(b, data));
        int for_right_place = rotation<reverse_rotation ? rotation : reverse_rotation;

        int for_top = be_rotated(temp) ? HowManyRotation_to_top(temp, temp->data) : HowManyReverseRotation_to_top(temp, temp->data);
        int total = for_top + for_right_place;

        if (total < min_opration)
        {
            min_opration = total;
            winner = temp;
        }

		temp = temp->prev;
    }

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
		int for_top = r_to_top < rr_to_top ? r_to_top : rr_to_top;
		int for_right_place = rotation<reverse_rotation ? rotation : reverse_rotation;



		// print_node(*a);
		// print_node(*b);




		
		// int	limiting_factor = 0;

		// if (for_top > for_right_place && for_right_place > 0)
		// {
		// 	limiting_factor = for_right_place;
		// 	for_right_place = 0;
		// 	for_top -= limiting_factor;
		// }
		// else if (for_right_place > for_top && for_top > 0)
		// {
		// 	limiting_factor = for_top;
		// 	for_top  = 0;
		// 	for_right_place -= limiting_factor;

		// }
		// int L = 0;
		// while ((L < limiting_factor) && (limiting_factor > 0))
		// {
		// 	if ((r_to_top < rr_to_top) && (rotation < reverse_rotation))
		// 	{
		// 		rr(a, b);
		// 		printf("rr\n");
		// 	}
		// 	else if ((r_to_top > rr_to_top) && (rotation > reverse_rotation))
		// 	{
		// 		rrr(a, b);
		// 		printf("rrr\n");
		// 	}
		// 	L++;
		// }






		int i = 0;
		while (i < for_top)
		{
			if (r_to_top < rr_to_top)
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
			if(rotation < reverse_rotation)
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

		stop = three_in_a(*a);
		


	}
	print_node(*b);

	printf( is_sorted(*b) ? "is sorted\n" : "not sorted\n");

}