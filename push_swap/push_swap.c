#include "push_swap.h"

void  ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
  if (ft_lstsize(stack_a) <= 3)
    ft_sort_type_a(stack_a, stack_b);
  else
    ft_sort_type_b(stack_a, stack_b);
}

void  push_swap(int argc, char **args)
{
  t_stack *stack_a;
  t_stack *stack_b;
  
  stack_a = (t_stack *)malloc(sizeof(t_stack));
  stack_b = (t_stack *)malloc(sizeof(t_stack));
  ft_init_stack(argc, &stack_a, args);
  if (ft_check_is_sorted(&stack_a))
  {
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
  }
  ft_del_stack(&stack_b);
  ft_sort_stack(&stack_a, &stack_b);
  ft_free_stack(&stack_a);
  ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error\n");
  push_swap(argc, ft_check_args(argc, argv));
	return (0);
}