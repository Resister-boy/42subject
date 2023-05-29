/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pwd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:15:28 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/22 22:16:09 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	atexit(check);
	
	(void)argc;
	(void)argv;
	(void)envp;
	exit(ft_pwd());
	return (0);
}