#include "./../push_swap.h"

t_node	*ft_lstlast(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}