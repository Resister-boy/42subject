#include "./../push_swap.h"

int ft_check_is_sorted(t_stack **stack)
{
  t_node  *head_node;
  t_node  *head_next_node;

  if (ft_lstsize(stack) == 0)
    return (-1);
  head_node = (*stack)->head;
  while (head_node != NULL && head_node->next != NULL)
  {
    head_next_node = head_node->next;
    if (head_node->num > head_next_node->num)
      return (0);
    head_node = head_node->next;
  }
  return (1);
}

void  ft_sort_type_a(t_stack **stack_a, t_stack **stack_b)
{
  size_t  stack_size;

  if (ft_check_is_sorted(stack_a) || ft_lstsize(stack_a) == 0 || ft_lstsize(stack_a) == 1)
    return ;
  stack_size = ft_lstsize(stack_a);
  if (stack_size == 2)
    ft_sa(stack_a);
  else if (stack_size == 3)
    ft_sort_stack_len_3(stack_a);
}

void  ft_sort_type_b(t_stack **stack_a, t_stack **stack_b)
{
  t_node  *half_node;
  t_node  *send_node;

  half_node = ft_find_half_node(stack_a);
  send_node = ft_get_next_node(stack_a, half_node);
  while (send_node != NULL)
  {
    ft_direct_command_a(stack_a, send_node);
    ft_pb(stack_a, stack_b);
    send_node = ft_get_next_node(stack_a, half_node);
  }
  ft_sort_upper(stack_a, stack_b);
  ft_sort_lower(stack_a, stack_b);
}

void  ft_direct_command_a(t_stack **stack_a, t_node *min_node)
{
  size_t  min_index;

  min_index = min_node->index;
  if (min_index >= ft_lstsize(stack_a) / 2)
  {
    while (min_node != (*stack_a)->head)
      ft_rra(stack_a);
  }
  else
  {
    while (min_node != (*stack_a)->head) 
      ft_ra(stack_a);
  }
}

void  ft_direct_command_b(t_stack **stack_b, t_node *max_node)
{
  size_t  max_index;

  max_index = max_node->index;
  if (max_index >= ft_lstsize(stack_b) / 2)
  {
    while (max_node != (*stack_b)->head)
      ft_rrb(stack_b);
  }
  else
  {
    while (max_node != (*stack_b)->head)
      ft_rb(stack_b);
  }
}

t_node  *ft_get_next_node(t_stack **stack_a, t_node *half_node)
{
  t_node  *current;

  current = (*stack_a)->head;
  while (current != NULL)
  {
    if (current->num <= half_node->num)
      return (current);
    current = current->next;
  }
  return (NULL);
}