#include "./../push_swap.h"

int ft_pa(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_push(stack_a, stack_b) == -1)
    return (-1);
  ft_print_command("pa\n");
  return (1);
}

int ft_pb(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_push(stack_b, stack_a) == -1)
    return (-1);
  ft_print_command("pb\n");
  return (1);
}
