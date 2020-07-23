#ifndef INT_NODE_H
# define INT_NODE_H

struct	s_int_node
{
	int                 value;
	struct s_int_node   *prev;
	struct s_int_node	*next;
};

typedef struct s_int_node	t_int_node;

t_int_node     *create_int_node(int value);

#endif