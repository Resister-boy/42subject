#include "./../push_swap.h"

void  ft_sort_stack_len_3(t_stack **stack)
{
  t_node  *head_node;
  t_node  *middle_node;
  t_node  *tail_node;

  head_node = (*stack)->head;
  middle_node = head_node->next;
  tail_node = (*stack)->tail;
  if (head_node->num < middle_node->num)
    ft_sa(stack);
  if (head_node->num < tail_node->num)
    ft_rra(stack);
  if (middle_node->num < tail_node->num)
  {
    ft_ra(stack);
    ft_sa(stack);
    ft_rra(stack);
  }
}