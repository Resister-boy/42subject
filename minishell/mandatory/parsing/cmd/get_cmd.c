/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:54 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/15 14:25:37 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cmd_path(char **paths, char *str)
{
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, str);
		ft_free((void **)&temp);
		if (!access(path, F_OK))
			return (path);
		ft_free((void **)&path);
	}
	return (ft_strdup(str));
}

void	parse_cmd_util(char *str, t_env_manager *e_man, t_pipe *node)
{
	if (check_dollar(str))
		no_quote_cmd_expand(str, e_man, node);
	else
		get_temp(str, node);
}

static void	handle_include_quote(char *str, t_pipe *node, t_env_manager *e_man)
{
	char	*buf;

	buf = handle_quote(str, e_man);
	get_temp(buf, node);
	free(buf);
}

int	parse_cmd(t_pipe *node, t_env_manager *e_man, char *prompt, int idx)
{
	int		start;
	int		status;
	char	*str;

	status = 0;
	start = idx;
	while (prompt[idx])
	{
		status = check_is_quote(prompt[idx], status);
		if (check_status(prompt[idx], status) || (status == NO_QUOTE && \
		prompt[idx] == '|'))
			break ;
		idx++;
	}
	str = ft_substr(prompt, start, idx - start);
	if (check_quote_include(str))
	{
		if (check_valid_quote(str) && !ft_free((void **)&str))
			return (-1);
		handle_include_quote(str, node, e_man);
	}
	else
		parse_cmd_util(str, e_man, node);
	ft_free((void **)&str);
	return (idx);
}

char	*get_env_path(t_env_manager *e_man, char *str)
{
	t_env	*envs;
	char	*path;
	char	**paths;

	if (str && !*str)
		path = ft_strdup(str);
	else if (ft_strchr(str, '/'))
		path = ft_strdup(str);
	else if (!ft_strncmp(str, ".", 2) || !ft_strncmp(str, "..", 3))
		path = ft_strdup(str);
	else
	{
		envs = get_env(e_man->head, "PATH");
		if (!envs || (envs && !(envs->value)))
			return (ft_strdup(str));
		paths = ft_split(envs->value, ':');
		path = get_cmd_path(paths, str);
		free_double_str(&paths);
	}
	return (path);
}
