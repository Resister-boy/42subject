/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_export_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:04 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/22 22:15:01 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check(void)
{
	system("leaks -q minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_env_manager	env_manager;

	atexit(check);
	
	(void)argc;
	(void)argv;
	(void)envp;

	/*
	
	./minishell 
	./minishell --
	./minishell -- -
	./minishell name name1= name2=2
	./minishell name 3 name1
	./minishell name=10 name=20
	./minishell 3 403        -02
	
	*/

	if (env_arr_to_list(&env_manager, envp))
		return (1);
	int ex_num = ft_export(argv + 1, &env_manager);
	ft_export(NULL, &env_manager);
	exit(ex_num);
	return (0);
}