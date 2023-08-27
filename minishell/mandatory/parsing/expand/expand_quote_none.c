/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_none.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:59:36 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:33:56 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_dollar_scope(char *str, int i)
{
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	handle_exit_status(int idx, char **buf, int *i)
{
	buf[(*i)] = expand_exit_status();
	idx++;
	return (idx);
}

static	int	handle_invalid_dollar(char **buf, int idx, int *i)
{
	buf[(*i)++] = ft_strdup("$");
	idx++;
	return (idx);
}

void	no_quote_expand_util(char *str, int idx, char **buf, \
t_env_manager *e_man)
{
	int	i;
	int	start;

	i = 0;
	while (str[idx] && !ft_isspace(str[idx]))
	{
		idx = handle_not_dollar(str, idx, buf, &i);
		if (str[idx] == '$' && is_valid_dollar(str, idx))
		{
			start = ++idx;
			if (str[idx] && str[idx] == '?')
				idx = handle_exit_status(idx, buf, &i);
			else
			{
				idx = get_dollar_scope(str, idx);
				handle_env_result(ft_substr(str, start, idx - start), \
				buf, i, e_man);
			}
			i++;
		}
		else if (str[idx] == '$' && !is_valid_dollar(str, idx))
			idx = handle_invalid_dollar(buf, idx, &i);
	}
}

void	no_quote_cmd_expand(char *str, t_env_manager *e_man, t_pipe *node)
{
	int		i;
	int		dollar;
	char	**buf;
	char	*cmd;

	i = 0;
	dollar = get_dollar_count(str);
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	no_quote_expand_util(str, i, buf, e_man);
	cmd = total_join(buf);
	free_double_str(&buf);
	connect_cmd_tmp(cmd, node);
	free(cmd);
}
