/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:36:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 15:26:26 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_str(char **backup, char *buf)
{
	char	*result;
	int		total_len;
	int		i;
	int		j;

	i = -1;
	if (!(*backup) || !buf)
	{
		ft_free_backup(backup);
		return (NULL);
	}
	total_len = ft_stringlen(*backup) + ft_stringlen(buf);
	result = ft_calloc((total_len + 1), sizeof(char), backup);
	if (!result)
		return (NULL);
	while ((*backup)[++i] != '\0')
		result[i] = (*backup)[i];
	j = -1;
	while (buf[++j] != '\0')
		result[i + j] = buf[j];
	if (*backup)
		ft_free_backup(backup);
	return (result);
}

int	ft_check_ln(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_backup(char **backup)
{
	if (!(*backup))
		return ;
	free(*backup);
	(*backup) = NULL;
}

void	*ft_calloc(size_t count, size_t size, char **backup)
{
	size_t	i;
	size_t	result_len;
	char	*result;

	result = (char *)malloc(count * size);
	if (!result)
	{
		if ((*backup) != NULL)
			ft_free_backup(backup);
		return (NULL);
	}
	i = 0;
	result_len = ((count * size) / sizeof(char));
	while (i < result_len)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

size_t	ft_stringlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
