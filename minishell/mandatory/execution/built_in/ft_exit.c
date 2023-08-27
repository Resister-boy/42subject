/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:46:55 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/06 13:13:31 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_exit_if_tty(void)
{
	if (isatty(STDIN_FILENO))
		ft_printf(STDOUT_FILENO, "exit\n");
	return (1);
}

static int	exit_with_print(int n)
{
	print_exit_if_tty();
	exit(n);
}

static int	is_long_long_range(char *str_num)
{
	int	len;
	int	pre_zero_cnt;

	pre_zero_cnt = 0;
	while (str_num[pre_zero_cnt + (str_num[0] == '-' || \
			str_num[0] == '+')] == '0')
		pre_zero_cnt++;
	len = ft_strlen(str_num) - pre_zero_cnt;
	if (len < 19 + (str_num[0] == '-' || str_num[0] == '+'))
		return (1);
	if ((len == 20 && str_num[0] == '-' \
	&& ft_strncmp(str_num + pre_zero_cnt + 1, "9223372036854775809", 19) < 0) \
			|| ((len == 19 + (str_num[0] == '+')) \
	&& ft_strncmp(str_num + pre_zero_cnt + (str_num[0] == '+'), \
			"9223372036854775808", 19) < 0))
		return (1);
	return (0);
}

int	ft_exit(char **args)
{
	int	i;

	if (!args || !*args)
		exit_with_print(0);
	i = is_ignore_first_arg(args[0]);
	if (i && !args[1])
		exit_with_print(0);
	if (is_num(args[i]) && is_long_long_range(args[i]))
	{
		if (args[i + 1] && print_exit_if_tty() && ft_printf(STDERR_FILENO, \
			"minishell: exit: too many arguments\n"))
			return (1);
		else
			exit_with_print((unsigned char)ft_atoi(args[i]));
	}
	else
	{
		print_exit_if_tty();
		ft_printf(STDERR_FILENO, \
			"minishell: exit: %s: numeric argument required\n", \
		args[i]);
		exit(255);
	}
	return (0);
}
