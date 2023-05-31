/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:56:29 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/31 15:13:50 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_envname(char *str, size_t *idx)
{
	size_t	start;

	start = (*idx) + 1;
	if (!str[start] || !ft_isalpha(str[start]) || str[start] == '_')
		return (ft_strdup(""));
	while (str[(*idx)] && !ft_isspace(str[(*idx)]) && str[(*idx)] != '$' && \
	(ft_isalpha(str[(*idx)]) || ft_isdigit(str[(*idx)]) || str[(*idx)] == '_'))
		(*idx)++;
	return (ft_substr(str, start, (*idx)));
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

void	expand_env(char *str, t_pipe *node)
{
	char	*expanded;

	expanded = getenv(str);
	connect_cmd_tmp(expanded, node);
}
