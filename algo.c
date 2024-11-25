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
    while (stack->next)
        stack = stack->next;
    return (stack);
}

int calc_rotation(int length, int index)
{
    return length - index - 1;
}

void    algo(t_node **a, t_node **b)
{
    push_to_node(a, b);
    push_to_node(a, b);
    rotate_node(b);
    push_to_node(a, b);

    push_to_node(a, b);
    // rotate_node(b);

    // rotate_node(b);
    // rotate_node(b);
    // rotate_node(b);
    // push_to_node(a, b);

    // //    rotate_node(b);
    // //     rotate_node(b);
    // //     rotate_node(b);
    // //     push_to_node(a, b);

    // //     push_to_node(a, b);


//    rotate_node(b);
//     rotate_node(b);
//     rotate_node(b);
//     push_to_node(a, b);

//     rotate_node(b);
//     rotate_node(b);
//     rotate_node(b);
//     rotate_node(b);
//     push_to_node(a, b);

    print_node(*a);
	print_node(*b);

    t_node *min = get_min(*b);
    int min_index = find_index(*b, min->data);
    t_node *last_a = get_last(*a);

    int rotation = 0;

    printf("min %d index: %d\n", min->data, min_index);

    while (last_a->data > min->data)
    {
        // rotation++;
        if (min->prev)
            min = min->prev;
        else
        {
            min = get_last(*b);
            // rotation = 0;
            // break;
        }
    }

    rotation = calc_rotation(node_len(*b), find_index(*b, min->data));

    printf("min %d\n", min->data);
    printf("rotation %d\n", rotation);



    // push_to_node(a, b);
    
    // if (is_sorted(*b))
    //     swap_last_two(b);

    // push_to_node(a, b);
}