#include "./../push_swap.h"

void  ft_free(char **str)
{
  size_t  i;

  i = 0;
  while (str[i])
    i++;
  while (i >= 0)
  {
    free(str[i]);
    i--;
  }
}

void  ft_del_stack(t_stack **stack)
{
  (*stack)->head = NULL;
  (*stack)->tail = NULL;
}

void  ft_free_node(t_node *node)
{
  node->prev = NULL;
  node->next = NULL;
  free(node);
}

void  ft_rebalance_index(t_stack **stack)
{
  t_node  *current;
  size_t  i;

  i = 1;
  current = (*stack)->head;
  while (current != NULL)
  {
    current->index = i;
    current = current->next;
    i++;
  }
}