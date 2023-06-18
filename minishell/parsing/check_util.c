/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:38:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/18 22:47:09 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_built_in(char *str)
{
	if (!ft_strcmp("echo", str) || !ft_strcmp("env", str) \
	|| !ft_strcmp("cd", str) || !ft_strcmp("export", str) \
	|| !ft_strcmp("pwd", str) || !ft_strcmp("unset", str))
		return (1);
	return (0);
}

int	is_empty_prompt(char *prompt)
{
	size_t	i;

	i = 0;
	while (prompt[i] && ft_isspace(prompt[i]))
		i++;
	if (ft_strlen(prompt) == i)
		return (1);
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
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_operator(char chr)
{
	if (chr == '|' || chr == '<' || chr == '>')
		return (1);
	return (0);
}
