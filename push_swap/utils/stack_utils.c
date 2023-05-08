/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:44:49 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 14:21:02 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_init_stack(t_stack **stack, char **args)
{
	size_t	i;
	t_node	*new_node;

	i = 0;
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	while (args[i] != NULL)
	{
		new_node = ft_lstnew(ft_atoi(args[i]), i);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	ft_free_str(&args);
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_init_rank(stack_a);
	if (ft_lstsize(stack_a) <= 5)
		ft_sort_type_a(stack_a, stack_b);
	else
	{
		ft_sort_type_b(stack_a, stack_b);
		ft_return_node(stack_a, stack_b);
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*temp;

	if ((*stack)->head == NULL)
		return ;
	current = (*stack)->head;
	while (current != NULL)
	{
		temp = current->next;
		current->prev = NULL;
		current->next = NULL;
		free(current);
		current = temp;
	}
}

void	ft_free_str(char ***str)
{
	size_t	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

void	ft_argc_small(char **argv, char ***args)
{
	(*args) = ft_split(argv[1], ' ');
	if (ft_get_double_len(*args) < 2)
	{
		ft_free_str(args);
		exit(0);
	}
}
