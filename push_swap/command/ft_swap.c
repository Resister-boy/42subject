#include "./../push_swap.h"

int ft_sa(t_stack **stack_a)
{
  if (ft_swap(stack_a) == -1)
    return (-1);
  ft_print_command("sa\n");
  return (1);
}

int ft_sb(t_stack **stack_b)
{
  if (ft_swap(stack_b) == -1)
    return (-1);
  ft_print_command("sb\n");
  return (1);
}

int ft_ss(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_swap(stack_a) == -1 || ft_swap(stack_b) == -1)
    return (-1);
  ft_print_command("ss\n");
  return (1);
}