/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 03:09:44 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/19 03:10:07 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_key_value(char *arg, char **key, char **value)
{
	char	*equal_pos;
	int		equal_len;

	equal_pos = ft_strchr(arg, '=');
	if (!equal_pos)
	{
		*key = ft_strdup(arg);
		*value = NULL;
		return (0);
	}
	equal_len = equal_pos - arg;
	*key = ft_substr(arg, 0, equal_len);
	if (!*key)
		return (1);
	*value = ft_substr(arg, equal_len + 1, \
	ft_strlen(arg) - (equal_len + 1));
	if (!*value)
	{
		free(*key);
		return (1);
	}
	return (0);
}

int	is_valid_env_key(char *key)
{
	int	i;

	if (!key)
		return (0);
	i = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (0);
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
	}
	return (1);
}
