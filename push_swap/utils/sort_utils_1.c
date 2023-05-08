/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:15:02 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:53:33 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_check_is_sorted(t_stack **stack)
{
	t_node	*head_node;
	t_node	*head_next_node;

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

t_node	*ft_get_available_node(t_stack **stack_a, size_t pivot)
{
	t_node		*current;

	current = (*stack_a)->head;
	if (current->rank < pivot)
		return (current);
	while (current->next != NULL)
	{
		if (current->rank < pivot)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_sort_type_a(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_size;

	if (ft_check_is_sorted(stack_a) || ft_lstsize(stack_a) == 0 || \
	ft_lstsize(stack_a) == 1)
		return ;
	stack_size = ft_lstsize(stack_a);
	if (stack_size == 2)
		ft_sa(stack_a);
	else if (stack_size == 3)
		ft_sort_stack_len_3(stack_a);
	else if (stack_size == 4)
		ft_sort_stack_len_4(stack_a, stack_b);
	else if (stack_size == 5)
		ft_sort_stack_len_5(stack_a, stack_b);
}

void	ft_sort_type_b(t_stack **stack_a, t_stack **stack_b)
{
	size_t		i;
	size_t		point[3];
	t_node		*current;

	i = 0;
	point[2] = ft_lstsize(stack_a);
	point[1] = (ft_lstsize(stack_a) / 3) * 2;
	point[0] = ft_lstsize(stack_a) / 3;
	while (i < 3 && ft_lstsize(stack_a) > 3)
	{
		current = ft_get_available_node(stack_a, point[i]);
		while (current != NULL && ft_lstsize(stack_a) > 3)
		{
			current = ft_get_available_node(stack_a, point[i]);
			if (current != NULL)
			{
				ft_send_node_top(stack_a, current);
				ft_pb(stack_a, stack_b);
			}
		}
		i++;
	}
	while (ft_lstsize(stack_a) > 3)
		ft_pb(stack_a, stack_b);
	ft_sort_stack_len_3(stack_a);
}

void	ft_check_args_kit(char **args)
{
	size_t		i;
	long long	num;

	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (!ft_check_only_num(args[i]))
			ft_error("Error\n");
		if (!ft_check_double(num, i, args))
			ft_error("Error\n");
		if (num < -2147483648 || num > 2147483647)
			ft_error("Error\n");
		i++;
	}
}
