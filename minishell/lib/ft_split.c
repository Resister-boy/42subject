/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:52:58 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:44:31 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

static char	**free_double_str(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	return (NULL);
}

static size_t	count_total_string(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static	size_t	count_single_str(char *s, char c)
{
	size_t	str_len;

	str_len = 0;
	while (*s)
	{
		if (*s != c)
			str_len++;
		else
			return (str_len);
		s++;
	}
	return (str_len);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	total_string;
	char	**result;

	i = -1;
	total_string = count_total_string(s, c);
	result = (char **)malloc(sizeof(char *) * (total_string + 1));
	if (!result)
		return (NULL);
	while (++i < total_string)
	{
		while (*s && *s == c)
			s++;
		result[i] = (char *)malloc(sizeof(char) * (count_single_str(s, c) + 1));
		if (!result[i] && free_double_str(result) == 0)
		{
			free(result);
			return (NULL);
		}
		ft_strlcpy(result[i], s, count_single_str(s, c) + 1);
		s += count_single_str(s, c);
	}
	result[i] = NULL;
	return (result);
}
