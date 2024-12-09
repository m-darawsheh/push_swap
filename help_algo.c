#include "push_swap.h"

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

