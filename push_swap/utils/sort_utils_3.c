/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:08:27 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/11 19:31:17 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_sort_case_min_top(t_stack **stack)
{
	ft_sa(stack);
	ft_ra(stack);
}

void	ft_sort_case_min_mid(t_stack **stack, t_node *head, t_node *min)
{
	if (head->next == min)
		ft_sa(stack);
	else
		ft_rra(stack);
}

void	ft_sort_case_min_bot(t_stack **stack, t_node *head, t_node *min)
{
	if (head->next == min)
		ft_ra(stack);
	else
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}

int	ft_find_short_cmd(t_command *cmd)
{
	if (cmd[0].count < cmd[1].count)
		return (cmd[0].count);
	else if (cmd[0].count > cmd[1].count)
		return (cmd[1].count);
	return (cmd[0].count);
}

void	ft_get_op_cmd(t_stack **stack_a, t_stack **stack_b, t_command *cmd)
{
	t_command	t_cmd[2];
	t_node		*current;

	current = (*stack_b)->head;
	cmd[0] = ft_find_node_from(stack_b, current);
	cmd[1] = ft_find_node_to(stack_a, current);
	if (current->next == NULL)
		return ;
	while (current->next != NULL)
	{
		current = current->next;
		if (current == NULL)
			return ;
		t_cmd[0] = ft_find_node_from(stack_b, current);
		t_cmd[1] = ft_find_node_to(stack_a, current);
		if (ft_get_total_cmd(cmd) > ft_get_total_cmd(t_cmd))
		{
			cmd[0] = ft_find_node_from(stack_b, current);
			cmd[1] = ft_find_node_to(stack_a, current);
		}
	}
}
