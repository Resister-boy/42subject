/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:34:23 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/27 16:02:58 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_case_stack_over(t_node **head, t_node **head_next, t_node **temp)
{
	(*temp) = (*head_next)->next;
	(*head_next)->next = (*head);
	(*head)->next = (*temp);
	(*temp)->prev = (*head);
}

void	ft_case_stack_two(t_stack **stack, t_node **head, t_node **head_next)
{
	(*head_next)->next = (*head);
	(*stack)->tail = (*head);
	(*head)->next = NULL;
}
