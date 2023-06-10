/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:54 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 17:47:37 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cmd_path(char **paths, char *str)
{
	size_t	i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], str);
		if (!access(path, F_OK))
			return (paths[i]);
		i++;
	}
	return (NULL);
}

int	parse_cmd(t_pipe *node, t_env_manager *e_man, char *prompt, size_t idx)
{
	size_t	start;
	char	*str;

	start = idx;
	while (prompt[idx] && !ft_isspace(prompt[idx]) && !is_operator(prompt[idx]))
		idx++;
	str = ft_substr(prompt, start, idx - start);
	if (check_dollar(str))
		no_quote_cmd_expand(str, e_man, node);
	else
		get_temp(str, node);
	return (idx);
}

char	*get_env_path(t_env_manager *e_man, char *str)
{
	t_env	*envs;
	char	*path;
	char	*program;
	char	**paths;
	size_t	i;

	i = 0;
	envs = get_env(e_man->head, "PATH");
	paths = ft_split(envs->value, ':');
	program = ft_strjoin("/", str);
	path = get_cmd_path(paths, program);
	if (!path)
		return (str);
	return (path);
}


void	get_temp(char *str, t_pipe *node)
{
	t_tmp	*tmp;
	t_tmp	*last;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	if (!str)
		tmp->args = ft_strdup("");
	else
		tmp->args = ft_strdup(str);
	tmp->next = NULL;
	last = get_lasttmp(node);
	if (!last)
		node->temp = tmp;
	else
		last->next = tmp;
}

char	**change_cmds(t_pipe *node, t_env_manager *e_man)
{
	size_t	i;
	size_t	len;
	t_tmp	*tmp;
	char	*path;
	char	**cmds;

	i = 1;
	if (!(node->temp))
		return (NULL);
	tmp = node->temp;
	len = get_tmpsize(node);
	cmds = (char **)malloc(sizeof(char *) * (len + 1));
	cmds[len] = NULL;
	path = get_env_path(e_man, tmp->args);
	cmds[0] = ft_strjoin(path, ft_strjoin("/", (tmp->args)));
	tmp = tmp->next;
	while (tmp)
	{
		cmds[i] = ft_strdup(tmp->args);
		tmp = tmp->next;
		i++;
	}
	return (cmds);
}
