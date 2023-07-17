/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:38:10 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 15:29:58 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_prev_dollar(int fd, int *cur_i, char *str)
{
	int	prev_i;

	prev_i = *cur_i;
	if (!str || !str[*cur_i])
		return (1);
	while (str[*cur_i])
	{
		if (str[*cur_i] == '$')
			break ;
		(*cur_i)++;
	}
	return (write(fd, str + prev_i, *cur_i - prev_i) && 0);
}

static int	print_env_expand(int fd, int *cur_i, char *str, \
	t_env_manager *env_manager)
{
	int		prev_i;
	char	*env_key;
	t_env	*env;

	prev_i = *cur_i;
	if (!str || !str[*cur_i])
		return (1);
	(*cur_i)++;
	if (!str[*cur_i])
		return (write(fd, str + prev_i, *cur_i - prev_i) || 1);
	if (str[*cur_i] == '?' && (*cur_i)++)
		return (ft_printf(fd, "%d", g_exit_status) && 0);
	if ((str[*cur_i] != '_' && !ft_isalpha(str[*cur_i])))
		return (write(fd, str + prev_i, *cur_i - prev_i) && 0);
	while (str[++(*cur_i)])
		if (str[*cur_i] != '_' && !ft_isalnum(str[*cur_i]))
			break ;
	env_key = ft_substr(str + prev_i, 1, *cur_i - prev_i - 1);
	env = get_env(env_manager->head, env_key);
	if (!env || !env->value || !*env->value)
		return (ft_free((void **)&env_key));
	return (ft_free((void **)&env_key) || \
		(write(fd, env->value, ft_strlen(env->value)) && 0));
}

static int	print_with_expand(int fd, char *str, t_env_manager *env_manager)
{
	int		i;

	i = 0;
	while (1)
		if (print_prev_dollar(fd, &i, str) || \
				print_env_expand(fd, &i, str, env_manager))
			return (0);
}

static void	heredoc_child(int fd, t_io *redir, t_env_manager *env_manager)
{
	char	*str;

	set_heredoc_signal();
	while (fd > 0)
	{
		str = readline("> ");
		if (!str)
			exit(0);
		if (!ft_strncmp(str, redir->filename, ft_strlen(redir->filename) + 1))
			exit(ft_free((void **)&str));
		if (redir->type == REDIR_HEREDOC_QUOTE)
			ft_putstr_fd(str, fd);
		else
			print_with_expand(fd, str, env_manager);
		ft_putstr_fd("\n", fd);
		ft_free((void **)&str);
	}
	exit(1);
}

int	ft_heredoc(t_io *redir, int i, \
	t_env_manager *env_manager, int *is_sigint)
{
	int		fd;
	pid_t	pid;
	int		child_status;
	int		signum;

	fd = new_heredoc_open(i);
	set_signal_parent();
	pid = fork();
	if (pid == 0)
		heredoc_child(fd, redir, env_manager);
	waitpid(pid, &child_status, 0);
	check_exit_status(child_status, &signum);
	if (WIFEXITED(child_status))
		*is_sigint = WEXITSTATUS(child_status);
	if (fd > -1)
	{
		close(fd);
		fd = heredoc_open(i);
	}
	return (fd);
}
