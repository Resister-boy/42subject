/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:45 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:14:03 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	allo_quote(char *str, int i)
{
	char	quote;

	quote = 0;
	if (str[i] == '\'')
		quote = '\'';
	else if (str[i] == '\"')
		quote = '\"';
	return (quote);
}

static	int	handle_quote_scope(char *str, int i, int *start)
{
	char	quote;

	quote = allo_quote(str, i);
	(*start) = ++i;
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}

static	int	handle_is_null(char *str, int i)
{
	if (str[i] != '\0')
		i++;
	return (i);
}

void	handle_quote_util(char *str, char **buf, t_env_manager *e_man)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = i;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			i = handle_quote_scope(str, i, &start);
			if (start < i)
				buf[j++] = expand_by_quote(str, start, i, e_man);
			i = handle_is_null(str, i);
		}
		else
		{
			start = i;
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
			if (start < i)
				buf[j++] = expand_by_quote(str, start, i, e_man);
		}
	}
}

char	*handle_quote(char *str, t_env_manager *e_man)
{
	char	**buf;
	int		len;
	char	*joined;

	len = get_quote_count(str);
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	handle_quote_util(str, buf, e_man);
	joined = total_join(buf);
	free_double_str(&buf);
	return (joined);
}
