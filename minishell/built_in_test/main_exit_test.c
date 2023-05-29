/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exit_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:55:34 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/22 21:56:05 by seonghle         ###   ########seoul.kr  */
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
	exit(ft_exit(argv + 1));
	return (0);
}