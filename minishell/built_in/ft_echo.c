/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:40:35 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/26 17:06:39 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_echo(char **args, int i)
{
	if (!args[i])
		printf("");
	else
		printf("%s", args[i]);
	if (args[i] && args[i + 1])
		printf(" ");
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
	if (is_set_option)
		while (args[++i] && check_option(args[i]))
			i++;
	while (args[i])
		print_echo(args, i++);
	if (!is_set_option)
		printf("\n");
	return (0);
}
