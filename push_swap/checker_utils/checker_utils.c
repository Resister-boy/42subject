/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:37:27 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 14:38:54 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "checker.h"

void	ft_proof_push(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp("pa", command, 2) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp("pb", command, 2) == 0)
		ft_push(stack_b, stack_a);
	else
		ft_print_result("KO\n");
}

void	ft_proof_swap(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp("sa", command, 2) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp("sb", command, 2) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp("ss", command, 2) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else
		ft_print_result("KO\n");
}

void	ft_proof_rotate(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp("ra", command, 2) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp("rb", command, 2) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp("rr", command, 2) == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
		ft_print_result("KO\n");
}

void	ft_proof_reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
char *command)
{
	if (ft_strncmp("rra", command, 3) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp("rrb", command, 3) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp("rrr", command, 3) == 0)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
	else
		ft_print_result("KO\n");
}
