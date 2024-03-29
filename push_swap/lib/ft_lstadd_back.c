/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:21:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 13:22:17 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_lstadd_back(t_stack **stack, t_node *new_node)
{
	t_node	*head_node;
	t_node	*last_node;

	if (ft_lstsize(stack) == 0)
	{
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
	}
	else
	{
	head_node = (*stack)->head;
	last_node = ft_lstlast(head_node);
	new_node->prev = last_node;
	last_node->next = new_node;
	(*stack)->tail = new_node;
	}
}
