
#include <stdio.h>
#include <stdlib.h>
#include "lib/libft.h"


typedef struct t_node
{
    int data;
    struct t_node *next;
    struct t_node *prev;
} t_node;

// "1 76 3 7 8"


///////       ** new function **           ///////
int	my_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		printf("ERROR!\n");
		exit(0);
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}


///////       ** new function **           ///////
void free_protiction(t_node *node)
{
    t_node *temp;
    while (node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
    exit(0);
}

void ft_add_back(t_node **head, int data)
{
    t_node *new;
    t_node *temp;
    new = malloc(sizeof(t_node));
    if (!new)
        free_protiction(*head);
    new->data = data;
    new->next = NULL;
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}


///////       ** new function **           ///////
t_node *ft_create_b(int argc)
{
    t_node *b;
    b = calloc (argc, sizeof(t_node));
    if (!b)
        free_protiction(b);
    return (b);
}

int	ft_isalpha_edit(char *c)
{
    int i;
    i = 0;
    while (c[i])
    {
        if ((c[i] > 64 && c[i] < 91) || (c[i] > 96 && c[i] < 123))
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void check_if_char(int argc, char *argv[])
{
    int i;
    i = 1;
    while (i < argc)
    {
        if (ft_isalpha_edit(argv[i]))
        {
            printf("ERROR!\n");
            exit(0);
        }
        i++;
    }
}
// 1 2 3 4

void check_if_duplicate(int argc, char *argv[])
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 1;
        while (j < argc)
        {
            if (i != j && my_atoi(argv[i]) == my_atoi(argv[j]))
            {
                printf("ERROR!\n");
                exit(0);
            }
            j++;
        }
        i++;
    }

}

void check_if_max_min(int argc, char *argv[])
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (my_atoi(argv[i]) > 2147483647 || my_atoi(argv[i]) < -2147483648)
        {
            printf("ERROR!\n");
            exit(0);
        }
        i++;
    }
}

void parse_arg(int argc, char *argv[], t_node **head)
{
    int i;
    // function check argv is { char[done] or  duplicate[done] or max and min number[done]}

    check_if_duplicate(argc, argv);
    check_if_max_min(argc, argv);
    check_if_char(argc, argv);

    i = 1;
    while (i < argc)
    {
        if (!*head)
        {
            *head = malloc(sizeof(t_node));
            if (!*head)
                free_protiction(*head);
            (*head)->data = my_atoi(argv[i]);
            (*head)->prev = NULL;
            (*head)->next = NULL;
        }
        else
            ft_add_back(head, my_atoi(argv[i]));
        i++;
    }

}

int main (int   argc, char    **argv)
{
    t_node *head = NULL;
    t_node *b;
    if (argc < 3)
        return (0);  
    parse_arg(argc, argv, &head);
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    
    // b = ft_create_b(argc);
    // int i;
    // i = 0;

    // printf ("%d\n how many elements in b list:\n", i);
    // while (b)
    // {
    //     printf ("%d", b->data);
    //     b = b->next;
    //     i++;
    // }
    printf("SUCCESS!\n");
}
