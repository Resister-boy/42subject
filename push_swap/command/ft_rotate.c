#include "./../push_swap.h"

int ft_ra(t_stack **stack_a)
{
  if (ft_rotate(stack_a) == -1)
    return (-1);
  ft_print_command("ra\n");
  return (1);
}

int ft_rb(t_stack **stack_b)
{
  if (ft_rotate(stack_b) == -1)
    return (-1);
  ft_print_command("rb\n");
  return (1);
}

int ft_rr(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_rotate(stack_a) == -1 || ft_rotate(stack_b) == -1)
    return (-1);
  ft_print_command("rr\n");
  return (1);
}