#include "./../push_swap.h"

size_t ft_lstsize(t_stack **stack)
{
	size_t				len;
	t_node				*current;

	len = 0;
	if ((*stack)->head == NULL)
		return (len);
	current = (*stack)->head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}