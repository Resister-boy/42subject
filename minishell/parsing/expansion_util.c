/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:42 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/06 15:33:06 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_dollar(char *str, size_t idx)
{
	if (str[idx] == '$' && str[idx + 1] && (ft_isalpha(str[idx + 1]) \
	|| str[idx + 1] == '_'))
		return (1);
	return (0);
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
