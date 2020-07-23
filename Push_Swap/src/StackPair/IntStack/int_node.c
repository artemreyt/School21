#include "int_node.h"
#include <stdlib.h>


t_int_node     *create_int_node(int value)
{
    t_int_node *new;

    new = (t_int_node *)malloc(sizeof(t_int_node));
    if (!new)
        return NULL;
    new->value = value;
    new->next = new;
    new->prev = new;
    return new;
}