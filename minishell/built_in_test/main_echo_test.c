/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_echo_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:02:58 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/22 22:05:58 by seonghle         ###   ########seoul.kr  */
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
	/*

	./minishell -n
	./minishell -nnnnnn ab
	./minishell adsf  sdajo adfsopj     asdp
	./minishell -n -n -nn ab
	./minishell -nnnnn -nnnnnn
	./minishell --
	./minishell - --
	./minishell -n a -n
	
	*/

	exit(ft_echo(argv + 1));
	return (0);
}