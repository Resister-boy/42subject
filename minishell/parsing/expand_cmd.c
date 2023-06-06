/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:13:26 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/06 16:11:25 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_env_cmd(char *str, t_pipe *node)
{
	char	*expanded;

	expanded = getenv(str);
	connect_cmd_tmp(expanded, node);
}

void	expand_env_quote(char *str, t_tmp *temp)
{
	size_t	i;
	size_t	k;
	size_t	len;
	size_t	start;
	char	**buf;

	i = 0;
	k = 0;
	len = get_dollar_count(str);
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	while (str[i])
	{
		if (str[i] && str[i++] == '$')
		{
			start = i;
			while (str[i] && !ft_isspace(str[i]) && str[i] != '$')
				i++;
			buf[k] = getenv(ft_substr(str, start, i));
		}
		k++;
	}
	temp->args = total_join(buf);
}

void	connect_cmd_tmp(char *str, t_pipe *node)
{
	size_t	i;
	char	**n_buf;

	i = 0;
	if (!is_all_space(str))
		get_temp(str, node);
	else
	{
		n_buf = ft_split(str, ' ');
		while (n_buf[i])
		{
			get_temp(n_buf[i], node);
			i++;
		}
	}
}

void	handle_expand(char *str, t_pipe *node)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		start = i;
		while (str[i] && str[i] != '$')
			i++;
		if (start < i)
			get_temp(ft_substr(str, start, i - start), node);
		if (is_valid_dollar(str, i))
		{
			i++;
			start = i;
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
			expand_env_cmd(ft_substr(str, start, i - start), node);
		}
	}
}
