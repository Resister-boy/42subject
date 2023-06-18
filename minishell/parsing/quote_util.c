/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:42:57 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/19 03:25:47 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_include(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

// 따옴표 확인
int	check_is_quote(char chr, int status)
{
	if ((status) == 0 && chr == '\'')
		return (1);
	else if ((status) == 0 && chr == '\"')
		return (2);
	else if (status == 1 && chr != '\'')
		return (1);
	else if (status == 2 && chr != '\"')
		return (2);
	return (0);
}

size_t	get_quote_count(char *str)
{
	size_t	i;
	size_t	count;
	int		status;

	i = 0;
	count = 0;
	status = 0;
	while (str[i])
	{
		status = check_is_quote(str[i], status);
		if (status == SINGLE_QUOTE)
		{
			if (i != 0 && str[i - 1] != '\'')
				count++;
		}
		else if (status == DOUBLE_QUOTE)
		{
			if (i != 0 && str[i] != '\"')
				count++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (count);
}
