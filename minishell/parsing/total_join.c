/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:13:06 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/19 01:50:53 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	total_len(char **str)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (str[idx] != NULL)
	{
		len += ft_strlen(str[idx]);
		idx++;
	}
	return (len);
}

char	*total_join(char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	char	*joined;

	i = 0;
	k = 0;
	len = total_len(str);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			joined[k++] = str[i][j++];
		i++;
	}
	joined[len] = '\0';
	return (joined);
}
