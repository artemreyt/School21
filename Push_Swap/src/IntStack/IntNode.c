#include "IntNode.h"
#include <stdlib.h>


IntNode_t     *createIntNode(int value)
{
    IntNode_t *new;

    new = (IntNode_t *)malloc(sizeof(IntNode_t));
    if (!new)
        return NULL;
    new->value = value;
    new->next = new;
    new->prev = new;
    return new;
}