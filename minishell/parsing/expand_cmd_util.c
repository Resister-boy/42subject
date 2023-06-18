/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:02:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/19 01:19:36 by jaehulee         ###   ########.fr       */
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
	size_t	i;
	size_t	dollar;
	char	**buf;
	char	*joined;

	i = 0;
	dollar = get_dollar_count(str);
	if (str[0] != '$')
		dollar += 1;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	quote_cmd_expand_util(str, i, buf, e_man);
	joined = total_join(buf);
	free_double_str(&buf);
	return (joined);
}

void	connect_cmd_tmp(char *cmd, t_pipe *node)
{
	size_t	i;
	char	**n_buf;

	i = 0;
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
