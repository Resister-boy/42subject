/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:40:35 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/07 15:40:35 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **args, int i)
{
	if (!args[i])
		ft_printf(STDOUT_FILENO, "");
	else
		ft_printf(STDOUT_FILENO, "%s", args[i]);
	if (args[i] && args[i + 1])
		ft_printf(STDOUT_FILENO, " ");
}

static int	check_option(char *str)
{
	int	i;

	if (!str || str[0] != '-' || (str[0] == '-' && !str[1]))
		return (0);
	i = 0;
	while (str[++i])
		if (str[i] != 'n')
			return (0);
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	is_set_option;

	i = 0;
	is_set_option = check_option(args[0]);
	if (is_set_option && ++i)
		while (args[i] && check_option(args[i]))
			i++;
	while (args[i])
		print_echo(args, i++);
	if (!is_set_option)
		ft_printf(STDOUT_FILENO, "\n");
	return (0);
}
