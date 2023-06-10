/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:05:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 20:50:10 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_dollar(char *str, size_t idx)
{
	if (str[idx] == '$' && str[idx + 1] && (ft_isalpha(str[idx + 1]) \
	|| str[idx + 1] == '_'))
		return (1);
	return (0);
}

void	handle_env_result(t_env *env, char **buf, size_t i)
{
	if (env == NULL)
		buf[i] = ft_strdup("");
	else
		buf[i] = env->value;
}

size_t	get_dollar_count(char *str)
{
	size_t	i;
	size_t	count;
	int		status;

	i = 0;
	count = 0;
	status = 0;
	while (str[i] && str[i] == '\"')
		i++;
	while (str[i] && str[i] != '\"')
	{
		if (is_valid_dollar(str, i))
		{
			status = 1;
			count++;
		}
		else if (status == 1 && !ft_isalnum(str[i]))
		{
			count++;
			status = 0;
		}
		i++;
	}
	return (count);
}
