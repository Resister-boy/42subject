#include "push_swap.h"

void print_stack(t_stack *stack)
{
  t_node *current;

  if (stack == NULL)
  {
    printf("Nothing Node\n");
    return ;
  }
  current = stack->head;
  printf("num: %d\n", current->num);
  printf("index: %d\n", current->index);
  printf("ptr: %p\n", current);
  printf("next: %p\n", current->next);
  printf("prev: %p\n", current->prev);
  while (current->next != NULL)
  {
    current = current->next;
    printf("num: %d\n", current->num);
    printf("index: %d\n", current->index);
    printf("ptr: %p\n", current);
    printf("next: %p\n", current->next);
    printf("prev: %p\n", current->prev);
  }
}

/*
    printf("-------- 1 --------\n");
    printf("-------- a --------\n");
    print_stack(stack_a);
    printf("-------- b --------\n");
    print_stack(stack_b);
    ft_push(&stack_a, &stack_b);
    printf("-------- 2 --------\n");
    printf("-------- a --------\n");
    print_stack(stack_a);
    printf("-------- b --------\n");
    print_stack(stack_b);
    ft_push(&stack_a, &stack_b);
    printf("-------- 3 --------\n");
    printf("-------- a --------\n");
    print_stack(stack_a);
    printf("-------- b --------\n");
    print_stack(stack_b);
    ft_push(&stack_b, &stack_a);
    printf("-------- 4 --------\n");
    printf("-------- a --------\n");
    print_stack(stack_a);
    printf("-------- b --------\n");
    print_stack(stack_b);
    ft_push(&stack_b, &stack_a);
    printf("-------- 5 --------\n");
    printf("-------- a --------\n");
    print_stack(stack_a);
    printf("-------- b --------\n");
    print_stack(stack_b);
**/

/**
    push_all_node_b(&stack_a, &stack_b);
    printf("-------- a ---------\n");
    print_stack(stack_a);
    printf("-------- b ---------\n");
    print_stack(stack_b);
    push_all_node_a(&stack_b, &stack_a);
    printf("-------- a ---------\n");
    print_stack(stack_a);
    printf("-------- b ---------\n");
    print_stack(stack_b);
*/