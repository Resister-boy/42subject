/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:47:01 by jaehulee          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/18 05:48:57 by seonghle         ###   ########seoul.kr  */
=======
/*   Updated: 2023/06/20 19:40:37 by seonghle         ###   ########seoul.kr  */
>>>>>>> da111faa5adfdf6c5ca6922fd020a340a94c91d1
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static void	ctrl_d(t_env_manager *env_manager, char *prompt)
{
	if (!prompt && ft_printf(1, "\x1b[1A\x1b[33;1m\x1b[22m\033[15Cexit\n\033[0m"))
		free_for_exit(env_manager, 0);
}

static int	parsing(t_pipe_manager *p_man, t_env_manager *env_manager, \
char *prompt)
{
	if (is_empty_prompt(prompt))
		return (0);
	parse_prompt(p_man, env_manager, prompt);
	print_pipe(p_man);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_manager	p_man;
	t_env_manager	env_manager;
	char			*prompt;

	(void)argc;
	(void)argv;
	set_signal();
	ft_memset(&p_man, 0, sizeof(t_pipe_manager));
	ft_memset(&env_manager, 0, sizeof(t_env_manager));
	if (env_arr_to_list(&env_manager, envp))
		return (1);
	while (1)
	{
		prompt = readline("minishell-0.1$ ");
		ctrl_d(&env_manager, prompt);
		if (*prompt)
			add_history(prompt);
		if (parsing(&p_man, &env_manager, prompt))
		{
			free(prompt);
			return (1);
		}
		if (!g_exit_status)
			ft_execution(&p_man, &env_manager);
		free_prompt(&p_man);
		free(prompt);
	}
	free_env(&env_manager);
	return (1);
}
