/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:47:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/30 22:34:56 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_redisplay();
}

static void set_signal(void)
{
	t_termios term;
	
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

static int	parsing(t_pipe_manager *p_man, t_env_manager *env_manager, char *prompt)
{
	size_t	i;

	i = 0;
	parse_prompt(p_man, env_manager, prompt);
	print_pipe(p_man);
	return (1);
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
		if (!prompt)
		{
			ft_putstr_fd("\x1b[1A", 1);
			ft_putstr_fd("\x1b[33;1m\x1b[22m\033[15C", 1);
			ft_putstr_fd("exit\n\033[0m", 1);
			exit(0);
		}
		if (!parsing(&p_man, &env_manager, prompt))
			return (0);
		add_history(prompt);
	}
	return (1);
}
