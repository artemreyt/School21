#ifndef INTLIST_H
# define INTLIST_H

struct	s_IntNode
{
    int                 value;
    struct s_IntNode    *prev;
    struct s_IntNode	*next;
};

typedef struct s_IntNode	IntNode_t;

IntNode_t     *createIntNode(int value);

#endif