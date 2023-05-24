/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:13:06 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 19:05:31 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

size_t	total_len(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
			j++;
		i++;
	}
	return (j);
}

char	*total_join(char **str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*joined;

	i = 0;
	len = total_len(str);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	joined[len] = '\0';
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			(*joined) = str[i][j];
			joined++;
			j++;
		}
		i++;
	}
	return (joined);
}
