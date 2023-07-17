/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:05:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:06:26 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_count(char *str, int idx, int *count)
{
	if (str[idx] == '$' && is_valid_dollar(str, idx))
	{
		if (str[++idx] == '?')
			idx++;
		else
			while (str[idx] && (ft_isalpha(str[idx]) || str[idx] == '_'))
				idx++;
		(*count)++;
	}
	return (idx);
}

int	is_valid_dollar(char *str, int idx)
{
	if (str[idx] == '$' && str[idx + 1] && (ft_isalpha(str[idx + 1]) \
	|| str[idx + 1] == '_' || str[idx + 1] == '?'))
		return (1);
	return (0);
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_valid_dollar(str, i))
			return (1);
		i++;
	}
	return (0);
}

void	handle_env_result(char *str, char **buf, int i, t_env_manager *e_man)
{
	t_env	*env;

	env = expand_env_cmd(e_man, str);
	if (env == NULL)
		buf[i] = ft_strdup("\0");
	else if (env->value == NULL)
		buf[i] = ft_strdup("\0");
	else
		buf[i] = ft_strdup(env->value);
	free(str);
}

int	get_dollar_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == '\"')
		i++;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$' && is_valid_dollar(str, i))
			i = handle_count(str, i, &count);
		else
		{
			while (str[i] && str[i] != '\"' && !is_valid_dollar(str, i))
				i++;
			count++;
		}
	}
	return (count);
}
