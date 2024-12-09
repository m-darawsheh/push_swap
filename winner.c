#include "push_swap.h"

int	find_numberes(t_node	*temp, t_node	*a, t_node	*b, int	data)
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
	return (x.total);

}


t_node*winner_node(t_node	*a, t_node	*b)
{
	t_node					*winner;
	t_node					*temp;
	int				min_opration;
	int 					x;

	winner = NULL;
	temp = a;
	min_opration = INT_MAX;
	while (temp)
	{

		int data;
		x = 0;

		data = right_place(temp, b);
		x = find_numberes(temp, a, b, data);
		if (x < min_opration)
		{	
			min_opration = x;
			winner = temp;
		}
		temp = temp->next;
	}
	return (winner);
}