/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:45 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/20 23:03:39 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_by_quote(char *str, size_t start, size_t idx, \
t_env_manager *e_man)
{
	int		status;
	char	*sub;
	char	*buf;
	size_t	i;

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
		buf = expand_env_cmd_util(e_man, sub);
		free(sub);
	}
	return (buf);
}

static char	**handle_quote_util(char *str, size_t len, t_env_manager *e_man)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**buf;

	i = 0;
	j = 0;
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	while (j < len)
	{
		start = i;
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
		if (start < i)
			buf[j++] = expand_by_quote(str, start, i, e_man);
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i++;
	}
	return (buf);
}

char	*handle_quote(char *str, t_env_manager *e_man)
{
	size_t	i;
	char	**buf;
	size_t	len;
	char	*joined;

	i = 0;
	len = get_quote_count(str);
	buf = handle_quote_util(str, len, e_man);
	joined = total_join(buf);
	free_double_str(&buf);
	return (joined);
}

void	change_cmds_util(t_tmp *tmp, char **cmds)
{
	size_t	i;

	i = 0;
	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		cmds[++i] = ft_strdup(tmp->args);
		tmp = tmp->next;
	}
}
