#include "push_swap.h"


		// must here call the khalele and choose the rotation or reverse rotation
		// do not forget to edite on khalele and the next step is suring if i walk on 
		// every single element in a and calculate how many rotation or reverse rotation
		// need it to be on the right place


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

bool	be_rotated(t_node *node)
{
	bool	is_rotated = true;
	int	local = find_index(node, node->data) + 1;
	int	length = node_len(node);
	float	middle = length / 2;

	if (local < middle)
		is_rotated = false;
	return (is_rotated);
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
		printf("winner is %d\n", winner->data);
		int data = right_place(winner, *b);
		int rotation = 0;
		int reverse_rotation = 0;

		rotation = calc_rotation(node_len(*b), find_index(*b, data));
		reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, data));

		int for_top = be_rotated(winner) ? HowManyRotation_to_top(winner, winner->data) : HowManyReverseRotation_to_top(winner, winner->data);
		int for_right_place = rotation<reverse_rotation ? rotation : reverse_rotation;

		int i = 0;

		while (i < for_top)
		{
			if (be_rotated(winner))
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
	print_node(*a);
	print_node(*b);

	printf( is_sorted(*b) ? "is sorted\n" : "not sorted\n");

}