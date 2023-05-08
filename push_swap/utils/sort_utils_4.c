/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:08:17 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:29:09 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

t_node	*ft_find_min_node(t_stack **stack)
{
	t_node	*current;
	t_node	*min;

	current = (*stack)->head;
	if (current == NULL)
		return (NULL);
	if (ft_lstsize(stack) == 1)
		return (current);
	min = current;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->num < min->num)
			min = current;
	}
	return (min);
}

t_node	*ft_find_max_node(t_stack **stack)
{
	t_node	*current;
	t_node	*max;

	current = (*stack)->head;
	if (current == NULL)
		return (NULL);
	if (ft_lstsize(stack) < 2)
		return (current);
	max = current;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->num > max->num)
			max = current;
	}
	return (max);
}

int	ft_get_escape_count(t_stack **stack, t_node *node)
{
	t_node	*head_node;
	int		count;

	head_node = (*stack)->head;
	count = 0;
	if (head_node == node)
		return (0);
	while (head_node->next != NULL)
	{
		head_node = head_node->next;
		count++;
		if (head_node == node)
			return (count);
	}
	return (-1);
}

int	ft_compare_command(int count1, int count2)
{
	if (count1 < count2)
		return (count2);
	return (count1);
}

int	ft_count_total_len(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += count_total_string(argv[i], ' ');
		i++;
	}
	return (len);
}
