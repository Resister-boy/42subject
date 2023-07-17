/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:13:06 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 12:58:50 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	total_len(char **str)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (str && str[idx] != NULL)
	{
		len += ft_strlen(str[idx]);
		idx++;
	}
	return (len);
}

char	*total_join(char **str)
{
	int		i;
	int		j;
	int		k;
	int		len;
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
