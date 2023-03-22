#include "./../push_swap.h"

void	ft_free_stack(t_stack	**stack)
{
  t_node  *current;
  t_node  *temp;

  if (ft_lstsize(stack) == 0)
    return ;
  current = (*stack)->head;
  while (current != NULL)
  {
    temp = current;
    ft_free_node(current);
    current = temp->next;
  }
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	(*stack) = NULL;
	free(*stack);
}

void ft_init_stack(int argc, t_stack  **stack, char **argv)
{
  size_t   i;
  char    **args;
  t_node  *new_node;

  i = 0;
  (*stack)->head = NULL;
  (*stack)->tail = NULL;
  if (argc == 2)
    args = ft_split(argv[1], ' ');
  else
  {
    i = 1;
		args = argv;
  }
  while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]), i);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}