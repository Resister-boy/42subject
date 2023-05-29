/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:46:55 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/26 17:06:42 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}

static int	exit_with_print(int n)
{
	printf("exit\n");
	exit(n);
}

int	ft_exit(char **args)
{
	int	i;

	if (!args || !*args)
		exit_with_print(0);
	i = is_ignore_first_arg(args[0]);
	if (i && !args[1])
		exit_with_print(0);
	if (is_num(args[i]))
	{
		if (args[i + 1] && printf("exit\nminishell: exit: too many arguments\n"))
			return (1);
		else
			exit_with_print((unsigned char)ft_atoi(args[i]));
	}
	else
	{
		printf("exit\nminishell: exit: %s: numeric argument required\n", \
		args[i]);
		exit(255);
	}
	return (0);
}
