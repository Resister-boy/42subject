/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:35:41 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../get_next_line/get_next_line.h"
#include "./../push_swap.h"
#include "checker.h"

void	ft_proof_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (command[0] == 'p')
		ft_proof_push(stack_a, stack_b, command);
	else if (command[0] == 's')
		ft_proof_swap(stack_a, stack_b, command);
	else if (command[0] == 'r' && ft_strlen(command) == 3)
		ft_proof_rotate(stack_a, stack_b, command);
	else if (command[0] == 'r' && ft_strlen(command) == 4)
		ft_proof_reverse_rotate(stack_a, stack_b, command);
}

void	ft_proof_is_sorted(t_stack **stack)
{
	t_node	*head_node;
	t_node	*head_next_node;

	head_node = (*stack)->head;
	while (head_node != NULL && head_node->next != NULL)
	{
		head_next_node = head_node->next;
		if (head_node->num > head_next_node->num)
			ft_print_result("KO\n");
		head_node = head_node->next;
	}
	ft_print_result("OK\n");
}

void	checker(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*command;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	ft_init_stack(&stack_a, args);
	ft_del_stack(&stack_b);
	if (ft_check_is_sorted(&stack_a))
	{
		ft_proof_is_sorted(&stack_a);
		ft_free_stack(&stack_a);
		free(stack_a);
		free(stack_b);
		return ;
	}
	while (get_next_line(0, &command))
		ft_proof_command(&stack_a, &stack_b, command);
	ft_proof_is_sorted(&stack_a);
	ft_free_stack(&stack_a);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	checker(ft_check_args(argc, argv));
	exit(0);
	return (0);
}
