/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:42:41 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/19 02:52:59 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unsigned_num(char *arg)
{
	int	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[0] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}

int	is_num(char *arg)
{
	int	i;

	if (!arg || !*arg)
		return (0);
	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}
