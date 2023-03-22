#include "./../push_swap.h"

int ft_rra(t_stack **stack_a)
{
  if (ft_reverse_rotate(stack_a) == -1)
    return (-1);
  ft_print_command("rra\n");
  return (1);
}

int ft_rrb(t_stack **stack_b)
{
  if (ft_reverse_rotate(stack_b) == -1)
    return (-1);
  ft_print_command("rrb\n");
  return (1);
}

int ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_reverse_rotate(stack_a) == -1 || ft_reverse_rotate(stack_b) == -1)
    return (-1);
  ft_print_command("rrr\n");
  return (1);
}