/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:42:57 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/20 23:02:36 by jaehulee         ###   ########.fr       */
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
	if (status == NO_QUOTE && chr == '\'')
		return (SINGLE_QUOTE);
	else if (status == NO_QUOTE && chr == '\"')
		return (DOUBLE_QUOTE);
	else if (status == SINGLE_QUOTE && chr == '\'')
		return (NO_QUOTE);
	else if (status == DOUBLE_QUOTE && chr == '\"')
		return (NO_QUOTE);
	else if (status == SINGLE_QUOTE && chr != '\'')
		return (SINGLE_QUOTE);
	else if (status == DOUBLE_QUOTE && chr != '\"')
		return (DOUBLE_QUOTE);
	return (NO_QUOTE);
}

size_t	get_quote_count(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i++;
		if (str[i] && str[i] != '\'' && str[i] != '\"')
			count++;
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
	}
	return (count);
}
