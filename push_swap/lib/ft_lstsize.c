/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:23:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/28 03:11:32 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

size_t	ft_lstsize(t_stack **stack)
{
	size_t				len;
	t_node				*current;

	len = 0;
	if ((*stack)->head == NULL)
		return (len);
	current = (*stack)->head;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
