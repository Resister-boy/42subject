/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:47:32 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/11 19:11:30 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_send_node_top(t_stack **stack_a, t_node *min_node)
{
	size_t	min_index;

	ft_rebalance_index(stack_a);
	min_index = min_node->index;
	if (ft_lstsize(stack_a) == 2 && min_index == 2)
	{
		ft_sa(stack_a);
		return ;
	}
	if ((min_index * 2) > ft_lstsize(stack_a))
	{
		while (min_node != (*stack_a)->head)
			ft_rra(stack_a);
	}
	else
	{
		while (min_node != (*stack_a)->head)
			ft_ra(stack_a);
	}
}

void	ft_execute_cmd(t_stack **stack_a, t_stack **stack_b, \
t_command *cmd)
{
	int	i;

	i = 0;
	if (cmd[0].flag == cmd[1].flag)
		i = ft_exe_dup_cmd(stack_a, stack_b, cmd);
	while (i < cmd[0].count)
	{
		if (cmd[0].flag == 1)
			ft_rb(stack_b);
		else if (cmd[0].flag == 2)
			ft_rrb(stack_b);
		i++;
	}
	if (cmd[0].flag != cmd[1].flag)
		i = 0;
	while (i < cmd[1].count)
	{
		if (cmd[1].flag == 1)
			ft_ra(stack_a);
		else if (cmd[1].flag == 2)
			ft_rra(stack_a);
		i++;
	}
}

void	ft_return_node(t_stack **stack_a, t_stack **stack_b)
{
	t_command	cmd[2];
	t_node		*min;

	while (ft_lstsize(stack_b) > 0)
	{
		ft_get_op_cmd(stack_a, stack_b, cmd);
		ft_execute_cmd(stack_a, stack_b, cmd);
		ft_pa(stack_a, stack_b);
	}
	if (ft_check_is_sorted(stack_a) == 0)
	{
		min = ft_find_min_node(stack_a);
		ft_send_node_top(stack_a, min);
	}
}

size_t	ft_get_total_cmd(t_command *cmd)
{
	size_t	cnt;

	if (cmd[0].flag == cmd[1].flag)
		cnt = ft_compare_command(cmd[0].count, cmd[1].count);
	else
		cnt = cmd[0].count + cmd[1].count;
	return (cnt);
}

void	ft_select_collect(t_node **current, t_node **collect)
{
	if ((*current)->next == NULL)
		(*collect) = (*current);
	else
		(*collect) = (*current)->next;
}
