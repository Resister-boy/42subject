/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:15:56 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/03 19:34:42 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_print_command(char *command)
{
	size_t	i;

	i = 0;
	while (command[i] != '\0')
	{
		write(1, &command[i], 1);
		i++;
	}
}

void	ft_error(char *error)
{
	size_t	i;

	i = 0;
	while (error[i] != '\0')
	{
		write(1, &error[i], 1);
		i++;
	}
	exit(0);
}

void	ft_print_result(char *result)
{
	size_t	i;

	i = 0;
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
	exit(0);
}

int	ft_abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (num * -1);
}
