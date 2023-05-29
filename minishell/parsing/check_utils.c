/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:38:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 04:17:24 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_dollar(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	check_quote(char chr, int *status)
{
	if ((*status) == 0 && chr == '\'')
	{
		(*status) = 1;
		return (1);
	}
	else if ((*status) == 0 && chr == '\"')
	{
		(*status) = 2;
		return (2);
	}
	else if (((*status) == 1) && (chr == '\''))
		(*status) = 0;
	else if (((*status) == 2) && (chr == '\"'))
		(*status) = 0;
	return (0);
}

int	ft_isspace(char chr)
{
	if (chr == '\t' || chr == '\n' || chr == '\v' \
	|| chr == '\f' || chr == '\r' || chr == ' ')
		return (1);
	return (0);
}

int	is_all_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}
