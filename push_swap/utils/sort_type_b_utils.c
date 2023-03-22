#include "./../push_swap.h"

void  ft_sort_upper(t_stack **stack_a, t_stack **stack_b)
{
  size_t  i;
  size_t  len;
  t_node  *min;

  i = 0;
  min = ft_find_min_node(stack_a);
  len = ft_lstsize(stack_a) - 1;
  while (i < len)
  {
      ft_direct_command_a(stack_a, min);
      ft_pb(stack_a, stack_b);
      min = ft_find_min_node(stack_a);
      i++;
  }
  ft_return_node(stack_a, stack_b, len);
}

void  ft_sort_lower(t_stack **stack_a, t_stack **stack_b)
{
  unsigned int i;
  unsigned int len;
  t_node  *max;

  i = 0;
  max = ft_find_max_node(stack_b);
  len = ft_lstsize(stack_b);
  while (i < len)
  {
      ft_direct_command_b(stack_b, max);
      ft_pa(stack_a, stack_b);
      max = ft_find_max_node(stack_b);
      i++;
  }
}

t_node  *ft_find_min_node(t_stack **stack)
{
  t_node  *current;
  t_node  *min;

  if (ft_lstsize(stack) == 0)
    return (NULL);
  current = (*stack)->head;
  if (ft_lstsize(stack) == 1)
    return (current);
  min = current;
  while (current->next != NULL)
  {
    current = current->next;
    if (current->num < min->num)
      min = current;
  }
  return (min);
}

t_node  *ft_find_max_node(t_stack **stack)
{
  t_node  *current;
  t_node  *max;

  if (ft_lstsize(stack) == 0)
    return (NULL);
  current = (*stack)->head;
  if (ft_lstsize(stack) == 1)
    return (current);
  max = current;
  while (current->next != NULL)
  {
    current = current->next;
    if (current->num > max->num)
      max = current;
  }
  return (max);
}

t_node  *ft_find_half_node(t_stack **stack)
{
  t_node  *max;
  t_node  *min;
  t_node  *max_temp;
  t_node  *min_temp;

  max = ft_find_max_node(stack);
  min = ft_find_min_node(stack);
  max_temp = max;
  min_temp = min;
  while (min_temp != max_temp)
  {
    max_temp = ft_find_prev_node(stack, max_temp);
    if (max_temp->num == min_temp->num)
      return (min_temp);
    min_temp = ft_find_next_node(stack, min_temp);
  }
  return (min_temp);
}

t_node  *ft_find_next_node(t_stack **stack, t_node *bottom)
{
  t_node  *current;
  t_node  *temp;

  current = (*stack)->head;
  temp = NULL;
  while (current->next != NULL)
  {
    current = current->next;
    if (bottom->num < current->num && (temp == NULL || current->num < temp->num))
      temp = current;
  }
  return (temp);
}

t_node  *ft_find_prev_node(t_stack **stack, t_node *top)
{
  t_node  *current;
  t_node  *temp;

  current = (*stack)->head;
  temp = NULL;
  while (current->next != NULL)
  {
    current = current->next;
    if (top->num > current->num && (temp == NULL || current->num > temp->num))
      temp = current;
  }
  return (temp);
}

void  ft_return_node(t_stack **stack_a, t_stack **stack_b, int count)
{
  size_t  i;

  i = 0;
  while (i < count)
  {
    ft_pa(stack_a, stack_b);
    i++;
  }
}