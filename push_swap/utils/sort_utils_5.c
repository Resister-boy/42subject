/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:28:23 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/11 19:06:07 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_node	*ft_find_min_next_node(t_stack **stack, t_node *bottom)
{
	t_node	*current;
	t_node	*temp;

	current = (*stack)->head;
	temp = NULL;
	while (current != NULL)
	{
		if (bottom->num < current->num && (temp == NULL || \
		current->num < temp->num))
			temp = current;
		current = current->next;
	}
	return (temp);
}

t_node	*ft_find_max_prev_node(t_stack **stack, t_node *top)
{
	t_node	*current;
	t_node	*temp;

	current = (*stack)->head;
	temp = NULL;
	while (current != NULL)
	{
		if (top->num > current->num && (temp == NULL || \
		current->num > temp->num))
			temp = current;
		current = current->next;
	}
	return (temp);
}

t_command	ft_find_node_from(t_stack **stack_b, t_node *node)
{
	t_command	command_b;

	ft_rebalance_index(stack_b);
	if ((*stack_b)->head == node)
	{
		command_b.count = 0;
		command_b.flag = 0;
	}
	else if (ft_lstsize(stack_b) > (node->index) * 2)
	{
		command_b.count = node->index;
		command_b.flag = 1;
	}
	else
	{
		command_b.count = ft_lstsize(stack_b) - (node->index);
		command_b.flag = 2;
	}
	return (command_b);
}

t_command	ft_find_node_to(t_stack **stack_a, t_node *node)
{
	t_node		*collect;
	t_command	command_a;

	collect = ft_get_collect_node(stack_a, node);
	ft_rebalance_index(stack_a);
	if (ft_lstsize(stack_a) > (collect->index) * 2)
	{
		command_a.count = collect->index;
		command_a.flag = 1;
	}
	else
	{
		command_a.count = ft_lstsize(stack_a) - (collect->index);
		command_a.flag = 2;
	}
	return (command_a);
}

t_node	*ft_get_collect_node(t_stack **stack_a, t_node *node)
{
	int		diff;
	t_node	*collect;
	t_node	*current;

	diff = 0;
	if (ft_find_min_node(stack_a)->num > node->num || \
	ft_find_max_node(stack_a)->num < node->num)
		return (ft_find_min_node(stack_a));
	current = (*stack_a)->head;
	if ((*stack_a)->tail->num < node->num && current->num > node->num)
		return (current);
	while (current->next != NULL)
	{
		if (current->num < node->num && current->next->num > node->num)
		{
			if (diff == 0 || ft_abs(node->num - current->num) < diff)
			{
				diff = ft_abs(node->num - current->num);
				ft_select_collect(&current, &collect);
			}
		}
		current = current->next;
	}
	return (collect);
}
