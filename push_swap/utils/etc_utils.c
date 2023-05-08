/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:17:03 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/11 19:05:35 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_del_stack(t_stack **stack)
{
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
}

void	ft_rebalance_index(t_stack **stack)
{
	t_node	*current;
	size_t	i;

	i = 0;
	current = (*stack)->head;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}
