/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:59:36 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 20:51:20 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	no_quote_expand_util(char *str, size_t idx, char **buf, \
t_env_manager *e_man)
{
	size_t	i;
	size_t	start;
	t_env	*env;

	i = 0;
	while (str[idx] && !ft_isspace(str[idx]))
	{
		start = idx;
		while (str[idx] && str[idx] != '$')
			idx++;
		if (start < idx)
			buf[i++] = ft_substr(str, start, idx - start);
		if (is_valid_dollar(str, idx))
		{
			idx++;
			start = idx;
			while (str[idx] && (ft_isalnum(str[idx]) || str[idx] == '_'))
				idx++;
			env = expand_env_cmd(e_man, ft_substr(str, start, idx - start));
			handle_env_result(env, buf, i);
			i++;
		}
	}
}

static void	quote_cmd_expand_util(char *str, size_t idx, char **buf, \
t_env_manager *e_man)
{
	size_t	i;
	size_t	start;
	t_env	*env;

	i = 0;
	while (str[idx] && !ft_isspace(str[idx]))
	{
		start = idx;
		while (str[i] && str[idx] != '$')
			idx++;
		if (start < idx)
			buf[i++] = ft_substr(str, start, idx - start);
		if (is_valid_dollar(str, idx))
		{
			idx++;
			start = idx;
			while (str[idx] && (ft_isalnum(str[idx]) || str[idx] == '_'))
				idx++;
			env = expand_env_cmd(e_man, ft_substr(str, start, idx - start));
			handle_env_result(env, buf, i);
			i++;
		}
	}
}

void	no_quote_cmd_expand(char *str, t_env_manager *e_man, t_pipe *node)
{
	size_t	i;
	size_t	dollar;
	char	**buf;
	char	*cmd;

	i = 0;
	dollar = get_dollar_count(str);
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	if (str[i] != '$')
		dollar += 1;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	no_quote_expand_util(str, i, buf, e_man);
	cmd = total_join(buf);
	connect_cmd_tmp(cmd, node);
}

void	quote_cmd_expand(char *str, t_env_manager *e_man, t_tmp *temp)
{
	size_t	i;
	size_t	dollar;
	char	**buf;

	i = 0;
	dollar = get_dollar_count(str);
	while (str[i] != '\0' && ft_isspace(str[i]) && str[i] != '\"')
		i++;
	if (str[i] == '\"' && str[i + 1] == '$')
		dollar += 1;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	quote_cmd_expand_util(str, i, buf, e_man);
	temp->args = total_join(buf);
}
