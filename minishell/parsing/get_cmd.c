/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:54 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/19 02:45:54 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 명령어 유효 경로 확인 및 변환
static char	*get_cmd_path(char **paths, char *str)
{
	size_t	i;
	char	*path;
	char	*temp;

	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, str);
		free(temp);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
	}
	return (ft_strdup(str));
}

static void	parse_cmd_util(char *str, t_env_manager *e_man, t_pipe *node)
{
	if (check_dollar(str))
		no_quote_cmd_expand(str, e_man, node);
	else
		get_temp(str, node);
}

// 명령어 파싱
int	parse_cmd(t_pipe *node, t_env_manager *e_man, char *prompt, size_t idx)
{
	size_t	start;
	int		status;
	char	*str;

	status = 0;
	start = idx;
	while (prompt[idx])
	{
		status = check_is_quote(prompt[idx], status);
		if (status == 0 && (ft_isspace(prompt[idx]) || \
		is_operator(prompt[idx])))
			break ;
		idx++;
	}
	str = ft_substr(prompt, start, idx - start);
	if (check_quote_include(str))
		get_temp(handle_quote(str, e_man), node);
	else
		parse_cmd_util(str, e_man, node);
	free(str);
	return (idx);
}

// 명령어 경로 얻는것
char	*get_env_path(t_env_manager *e_man, char *str)
{
	t_env	*envs;
	char	*path;
	char	**paths;

	envs = get_env(e_man->head, "PATH");
	paths = ft_split(envs->value, ':');
	path = get_cmd_path(paths, str);
	free_double_str(&paths);
	return (path);
}

char	**change_cmds(t_pipe *node, t_env_manager *e_man)
{
	size_t	len;
	t_tmp	*tmp;
	char	*path;
	char	**cmds;

	if (!node || !(node->temp))
		return (NULL);
	tmp = node->temp;
	len = get_tmpsize(node);
	cmds = (char **)malloc(sizeof(char *) * (len + 1));
	cmds[len] = NULL;
	if (check_built_in(tmp->args))
		path = ft_strdup(tmp->args);
	else
		path = get_env_path(e_man, tmp->args);
	cmds[0] = path;
	change_cmds_util(tmp, cmds);
	return (cmds);
}
