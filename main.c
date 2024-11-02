
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

void ft_add_back(t_node **head, int data)
{
    t_node *new;
    t_node *temp;
    new = malloc(sizeof(t_node));
    new->data = data;
    new->next = NULL;
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
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
            if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
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
        if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
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
            (*head)->data = ft_atoi(argv[i]);
            (*head)->prev = NULL;
            (*head)->next = NULL;
        }
        else
            ft_add_back(head, ft_atoi(argv[i]));
        i++;
    }

}

int main (int   argc, char    **argv)
{
    t_node *head = NULL;
    if (argc < 3)
        return (0);  
    parse_arg(argc, argv, &head);
    printf("SUCCESS!\n");
}