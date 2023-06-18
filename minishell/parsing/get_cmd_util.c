/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:45 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/19 02:46:53 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**handle_quote_util(char *str)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;
	char	**buf;

	i = 0;
	j = 0;
	len = get_quote_count(str);
	if (str[0] && (str[0] == '\'' || str[0] == '\"' ))
		len++;
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	while (j < len)
	{
		start = i;
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
		if (start < i)
		{
			buf[j] = ft_substr(str, start, i - start);
			j++;
			i++;
		}
	}
	return (buf);
}

char	*handle_quote(char *str, t_env_manager *e_man)
{
	size_t	i;
	char	**buf;
	size_t	len;
	char	**ex;
	char	*joined;

	i = 0;
	buf = handle_quote_util(str);
	len = ft_strslen(buf);
	ex = (char **)malloc(sizeof(char *) * (len + 1));
	ex[len] = NULL;
	while (buf[i])
	{
		ex[i] = expand_env_cmd_util(e_man, buf[i]);
		i++;
	}
	joined = total_join(ex);
	free_double_str(&buf);
	free_double_str(&ex);
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
