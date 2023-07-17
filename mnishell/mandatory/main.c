/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:47:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 15:31:53 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ctrl_d(t_env_manager *env_manager, char *prompt)
{
	if (!prompt && ft_printf(STDOUT_FILENO, "\033[uexit\n"))
		free_for_exit(env_manager, 0);
}

static int	init_main_var(int argc, char **argv, \
	t_pipe_manager *p_man, t_env_manager *env_manager)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf(STDERR_FILENO, "Argument Error\n");
		exit(1);
	}
	ft_memset(p_man, 0, sizeof(t_pipe_manager));
	ft_memset(env_manager, 0, sizeof(t_env_manager));
	return (0);
}

static int	close_all_fd(t_pipe_manager *p_man)
{
	t_pipe	*temp;

	temp = p_man->head;
	while (temp)
	{
		if (temp->in_fd)
			close(temp->in_fd);
		if (temp->out_fd)
			close(temp->out_fd);
		temp = temp->next;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_manager	p_man;
	t_env_manager	env_manager;
	char			*prompt;

	init_main_var(argc, argv, &p_man, &env_manager);
	if (env_arr_to_list(&env_manager, envp))
		return (1);
	while (1)
	{
		set_signal();
		unlink_temp_file();
		prompt = readline("minishell-0.1$ \033[s");
		ctrl_d(&env_manager, prompt);
		if (*prompt)
			add_history(prompt);
		if (!parsing(&p_man, &env_manager, prompt))
			ft_execution(&p_man, &env_manager);
		close_all_fd(&p_man);
		free_prompt(&p_man);
		ft_free((void **)&prompt);
	}
	return (!free_env(&env_manager));
}
