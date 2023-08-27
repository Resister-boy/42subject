/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expand_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:44:40 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:11:58 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_cmds_util(t_tmp *tmp, char **cmds)
{
	int	i;

	i = 0;
	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		cmds[++i] = ft_strdup(tmp->args);
		tmp = tmp->next;
	}
}

int	handle_not_dollar(char *str, int idx, char **buf, int *i)
{
	int	start;

	start = idx;
	while (str[idx] && !is_valid_dollar(str, idx))
		idx++;
	if (start < idx)
		buf[(*i)++] = ft_substr(str, start, idx - start);
	return (idx);
}

char	*expand_by_quote(char *str, int start, int idx, \
t_env_manager *e_man)
{
	int		status;
	char	*sub;
	char	*buf;
	int		i;

	i = 0;
	status = 0;
	while (i < idx)
	{
		status = check_is_quote(str[i], status);
		i++;
	}
	if (status == SINGLE_QUOTE)
		buf = ft_substr(str, start, idx - start);
	else
	{
		sub = ft_substr(str, start, idx - start);
		if (!check_dollar(sub))
			buf = ft_strdup(sub);
		else
			buf = expand_env_cmd_util(e_man, sub);
		ft_free((void **)&sub);
	}
	return (buf);
}

void	quote_cmd_expand(char *str, t_env_manager *e_man, t_tmp *temp)
{
	int		i;
	int		dollar;
	char	**buf;

	i = 0;
	dollar = get_dollar_count(str);
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	quote_cmd_expand_util(str, i, buf, e_man);
	temp->args = total_join(buf);
}

void	quote_cmd_expand_util(char *str, int idx, char **buf, \
t_env_manager *e_man)
{
	int	i;
	int	start;

	i = 0;
	while (str[idx])
	{
		start = idx;
		while (str[idx] && !is_valid_dollar(str, idx))
			idx++;
		if (start < idx)
			buf[i++] = ft_substr(str, start, idx - start);
		if (is_valid_dollar(str, idx))
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
	}
}
