/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_unset_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:17:10 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/22 22:17:32 by seonghle         ###   ########seoul.kr  */
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

	if (env_arr_to_list(&env_manager, envp))
		return (1);
	exit(ft_unset(argv + 1, &env_manager));
	return (0);
}