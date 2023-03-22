#include "./../push_swap.h"

t_node	*ft_lstnew(int word, int idx)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->num = word;
  new_node->index = idx;
	return (new_node);
}