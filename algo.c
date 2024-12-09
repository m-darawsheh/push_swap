#include "push_swap.h"


bool the_list_is_empty(t_node *stack)
{
	if (!stack)
		return (true);
	return (false);
}

bool	is_sorted_a(t_node *node)
{
	t_node	*temp;

	temp = node;
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

t_number	find_rights(t_node	*temp, t_node	*a, t_node	*b, int	data)
{
	t_number	x;

	x.rotation = calc_rotation(node_len(b), find_index(b, data));
	x.reverse_rotation = calc_reverse_rotation(node_len(b), find_index(b, data));
	if (x.rotation < x.reverse_rotation)
		x.for_right_place = x.rotation;
	else
		x.for_right_place = x.reverse_rotation;
	x.rotation_a = calc_rotation(node_len(a), find_index(a, temp->data));
	x.reverse_rotation_a = calc_reverse_rotation(node_len(a), find_index(a, temp->data));
	if (x.rotation_a < x.reverse_rotation_a)    
		x.for_top = x.rotation_a;
	else
		x.for_top = x.reverse_rotation_a;
	x.total = x.for_top + x.for_right_place;
	return (x);
}

void do_rotations_a(t_number x, t_node **a)
{
	int	i;

	i = 0;
	while (i < x.for_top)
	{
		if (x.rotation_a < x.reverse_rotation_a)
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
}

void do_rotations_b(t_number x, t_node **b)
{
	int	i;

	i = 0;
	while (i < x.for_right_place)
	{
		if (x.rotation < x.reverse_rotation)
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

}
void	make_b_inverse(t_node **b)
{
	t_node	*max;
	t_number	x;
	max = get_max(*b);
	x.rotation = calc_rotation(node_len(*b), find_index(*b, max->data));
	x.reverse_rotation = calc_reverse_rotation(node_len(*b), find_index(*b, max->data));
	if(x.rotation < x.reverse_rotation)
		x.for_top = x.rotation;
	else
		x.for_top = x.reverse_rotation;
	int i = 0;
	while (i < x.for_top)
	{
		if (x.rotation < x.reverse_rotation)
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
}


void pushing(t_node **b, t_node **a)
{
	int	push;
	int	i;

	push = node_len(*b);
	i = 0;
	while (i < push)
	{
		push_to_node(b, a);
		printf("pa\n");
		i++;
	}
}

void	algo(t_node **a, t_node **b)
{
	push_to_node(a, b);
	push_to_node(a, b);
	printf("pb\n");
	printf("pb\n");

	while (!the_list_is_empty(*a))
	{
		t_node *winner = winner_node(*a, *b);
		int Data = right_place(winner, *b);

		t_number x = find_rights(winner, *a, *b, Data);

		do_rotations_a(x, a);
		do_rotations_b(x, b);
		push_to_node(a, b);
		printf("pb\n");
	}
	make_b_inverse(b);
	pushing(b, a);

}
