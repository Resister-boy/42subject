/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cd_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:34:17 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/26 12:03:18 by seonghle         ###   ########seoul.kr  */
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
	./minishell ..
	./minishell -
	./minishell --
	./minishell ../..
	./minishell asdpfo
	./minishell -- ..
	./minishell .. ../..
	
	*/

	if (env_arr_to_list(&env_manager, envp))
		return (1);
	char *prev_path = getcwd(NULL, 0);
	printf("prev cd path : [%s]\n", prev_path);
	free(prev_path);

	int code = ft_cd(argv + 1, &env_manager);
	
	char *after_path = getcwd(NULL, 0);
	printf("after cd path : [%s]\n", after_path);
	free(after_path);
	
	t_env *pwd = get_env(env_manager.head, "PWD");
	if (pwd)
		printf("PWD : [%s]\n", pwd->value);
	
	t_env *oldpwd = get_env(env_manager.head, "OLDPWD");
	if (oldpwd)
		printf("OLDPWD : [%s]\n", oldpwd->value);
	else
		printf("OLDPWD : []\n");
	
	free_all_node(env_manager.head);
	return (code);
}