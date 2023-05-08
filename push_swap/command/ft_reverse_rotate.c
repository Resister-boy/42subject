/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:26:16 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 13:41:23 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_rra(t_stack **stack_a)
{
	if (ft_reverse_rotate(stack_a) == -1)
		return (-1);
	ft_print_command("rra\n");
	return (1);
}

int	ft_rrb(t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_b) == -1)
		return (-1);
	ft_print_command("rrb\n");
	return (1);
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_a) == -1 || ft_reverse_rotate(stack_b) == -1)
		return (-1);
	ft_print_command("rrr\n");
	return (1);
}
