/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:07:08 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/11 18:50:16 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_sort_stack_len_3(t_stack **stack)
{
	t_node	*head_node;
	t_node	*min_node;
	t_node	*min_next_node;

	head_node = (*stack)->head;
	min_node = ft_find_min_node(stack);
	min_next_node = ft_find_min_next_node(stack, min_node);
	if (ft_check_is_sorted(stack))
		return ;
	if (head_node == min_node && head_node->next != min_next_node)
		ft_sort_case_min_top(stack);
	else if (head_node == min_next_node)
		ft_sort_case_min_mid(stack, head_node, min_node);
	else
		ft_sort_case_min_bot(stack, head_node, min_node);
}

void	ft_sort_stack_len_4(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = ft_get_escape_count(stack_a, ft_find_min_node(stack_a));
	if (ft_check_is_sorted(stack_a) || count == -1)
		return ;
	if (count == 1)
		ft_ra(stack_a);
	else if (count == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (count == 3)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_stack_len_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_stack_len_5(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = ft_get_escape_count(stack_a, ft_find_min_node(stack_a));
	if (ft_check_is_sorted(stack_a) || count == -1)
		return ;
	if (count == 1)
		ft_ra(stack_a);
	else if (count == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (count == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (count == 4)
		ft_rra(stack_a);
	if (ft_check_is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_stack_len_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_init_rank(t_stack **stack)
{
	size_t	rank;
	t_node	*max_node;
	t_node	*min_node;
	t_node	*temp;

	rank = 0;
	max_node = ft_find_max_node(stack);
	min_node = ft_find_min_node(stack);
	temp = min_node;
	while (max_node != min_node)
	{
		min_node->rank = rank;
		min_node = ft_find_min_next_node(stack, temp);
		temp = min_node;
		rank++;
	}
	max_node->rank = rank;
}

int	ft_exe_dup_cmd(t_stack **stack_a, t_stack **stack_b, t_command *cmd)
{
	int	i;

	i = 0;
	while (i < ft_find_short_cmd(cmd))
	{
		if (cmd[0].flag == 1)
			ft_rr(stack_a, stack_b);
		else if (cmd[0].flag == 2)
			ft_rrr(stack_a, stack_b);
		i++;
	}
	return (i);
}
