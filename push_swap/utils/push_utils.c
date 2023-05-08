/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:18:34 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:36:15 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_case_over_one(t_node **temp, t_node **head_from, \
t_stack **stack_from)
{
	(*temp) = (*head_from)->next;
	(*stack_from)->head = (*temp);
	(*temp)->prev = NULL;
}

void	ft_case_under_one(t_node **temp, t_stack **stack_from)
{
	(*temp) = NULL;
	(*stack_from)->head = NULL;
	(*stack_from)->tail = NULL;
}

void	ft_case_stack_null(t_stack **stack_to, t_node **head_from)
{
	(*stack_to)->tail = (*head_from);
	(*head_from)->next = NULL;
}

void	ft_case_stack_full(t_node **head_from, t_node **head_to)
{
	(*head_from)->next = (*head_to);
	(*head_to)->prev = (*head_from);
}
