/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:37:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/03 14:23:37 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_push(t_stack **stack_to, t_stack **stack_from)
{
	t_node	*head_to;
	t_node	*head_from;
	t_node	*temp;

	if (ft_lstsize(stack_from) == 0)
		return (0);
	head_to = (*stack_to)->head;
	head_from = (*stack_from)->head;
	if (ft_lstsize(stack_from) > 1)
		ft_case_over_one(&temp, &head_from, stack_from);
	else
		ft_case_under_one(&temp, stack_from);
	(*stack_to)->head = head_from;
	head_from->prev = NULL;
	if (head_to == NULL)
		ft_case_stack_null(stack_to, &head_from);
	else
		ft_case_stack_full(&head_from, &head_to);
	return (1);
}

int	ft_swap(t_stack **stack)
{
	t_node	*head_node;
	t_node	*head_next;
	t_node	*temp;
	size_t	stack_len;

	stack_len = ft_lstsize(stack);
	if (stack_len < 2)
		return (0);
	head_node = (*stack)->head;
	head_next = head_node->next;
	(*stack)->head = head_next;
	head_node->prev = head_next;
	head_next->prev = NULL;
	if (stack_len > 2)
		ft_case_stack_over(&head_node, &head_next, &temp);
	else if (stack_len == 2)
		ft_case_stack_two(stack, &head_node, &head_next);
	return (1);
}

int	ft_rotate(t_stack **stack)
{
	t_node	*head_node;
	t_node	*head_next;
	t_node	*tail_node;

	if (ft_lstsize(stack) < 2)
		return (0);
	head_node = (*stack)->head;
	tail_node = (*stack)->tail;
	head_next = head_node->next;
	head_next->prev = NULL;
	head_node->prev = tail_node;
	head_node->next = NULL;
	tail_node->next = head_node;
	(*stack)->head = head_next;
	(*stack)->tail = head_node;
	return (1);
}

int	ft_reverse_rotate(t_stack **stack)
{
	t_node	*head_node;
	t_node	*tail_node;
	t_node	*tail_prev;

	if (ft_lstsize(stack) < 2)
		return (0);
	head_node = (*stack)->head;
	tail_node = (*stack)->tail;
	tail_prev = tail_node->prev;
	tail_prev->next = NULL;
	head_node->prev = tail_node;
	tail_node->prev = NULL;
	tail_node->next = head_node;
	(*stack)->head = tail_node;
	(*stack)->tail = tail_prev;
	return (1);
}
