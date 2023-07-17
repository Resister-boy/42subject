/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:42:57 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:37:37 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_get_quote_count(char *str, int i, int *count, \
char quote)
{
	int	start;

	start = ++i;
	while (str[i] && str[i] != quote)
		i++;
	if (start < i)
		(*count)++;
	if (str[i] != '\0')
		i++;
	return (i);
}

int	check_quote_include(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

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

int	get_quote_count(char *str)
{
	int	i;
	int	start;
	int	count;

	i = 0;
	count = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
			i = handle_get_quote_count(str, i, &count, '\'');
		else if (str[i] && str[i] == '\"')
			i = handle_get_quote_count(str, i, &count, '\"');
		else
		{
			start = i;
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
			if (start < i)
				count++;
		}
	}
	return (count);
}
