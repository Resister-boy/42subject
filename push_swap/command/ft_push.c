/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:25:22 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 13:25:48 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	ft_print_command("pa\n");
	return (1);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	ft_print_command("pb\n");
	return (1);
}
