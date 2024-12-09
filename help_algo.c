#include "push_swap.h"

int	HowManyRotation_to_top(t_node	*stack, int	data)
{
	int	index;
	int	rotation;

	index = find_index(stack, data);
	rotation = calc_rotation(node_len(stack), index);
	return (rotation);
}
int	HowManyReverseRotation_to_top(t_node	*stack, int	data)
{
	int	index;
	int	reverse_rotation;

	index = find_index(stack, data);
	reverse_rotation = calc_reverse_rotation(node_len(stack), index);
	return (reverse_rotation);
}

int	right_place(t_node	*a, t_node	*b)
{

		t_node	*min;
		t_node	*temp;

		min = get_min(b);
		temp = min;
		while (a->data > min->data)
		{
			if (min->prev)
				min = min->prev;
			else
				min = get_last(b);

			if (temp->data == min->data)
			{
				if (min->next)
					return (min->next->data);
				else
					return (b->data);
			}
		}
		if (min->next)
			return (min->next->data);
		else
			return (b->data);
}
