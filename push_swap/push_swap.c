/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:31:39 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:57:18 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	ft_init_stack(&stack_a, args);
	if (ft_check_is_sorted(&stack_a))
	{
		ft_free_stack(&stack_a);
		free(stack_a);
		free(stack_b);
		return ;
	}
	ft_del_stack(&stack_b);
	ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(ft_check_args(argc, argv));
	exit(0);
	return (0);
}
