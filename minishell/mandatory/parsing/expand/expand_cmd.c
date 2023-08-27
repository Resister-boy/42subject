/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:02:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:22 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*expand_env_cmd(t_env_manager *e_man, char *str)
{
	t_env	*expanded;

	expanded = get_env(e_man->head, str);
	return (expanded);
}

char	*expand_env_cmd_util(t_env_manager *e_man, char *str)
{
	int		i;
	int		dollar;
	char	**buf;
	char	*joined;

	i = 0;
	dollar = get_dollar_count(str);
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	quote_cmd_expand_util(str, i, buf, e_man);
	joined = total_join(buf);
	free_double_str(&buf);
	return (joined);
}

char	*expand_exit_status(void)
{
	char	*str;

	str = ft_itoa(g_exit_status);
	return (str);
}

void	connect_cmd_tmp(char *cmd, t_pipe *node)
{
	int		i;
	char	**n_buf;

	i = 0;
	if (ft_strlen(cmd) == 0)
		return ;
	if (!is_all_space(cmd))
		get_temp(cmd, node);
	else
	{
		n_buf = ft_split(cmd, ' ');
		while (n_buf[i])
		{
			get_temp(n_buf[i], node);
			i++;
		}
		free_double_str(&n_buf);
	}
}

char	**change_cmds(t_pipe *node, t_env_manager *e_man)
{
	int		len;
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
