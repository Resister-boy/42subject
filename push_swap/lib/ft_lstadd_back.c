#include "./../push_swap.h"

void	ft_lstadd_back(t_stack **stack, t_node *new_node)
{
  t_node  *head_node;
  t_node  *last_node;

	if (ft_lstsize(stack) == 0)
  {
    (*stack)->head = new_node;
    (*stack)->tail = new_node;
  }
  else
  {
    head_node = (*stack)->head;
    last_node = ft_lstlast(head_node);
    new_node->prev = last_node;
    last_node->next = new_node;
    (*stack)->tail = new_node;
  }
}
