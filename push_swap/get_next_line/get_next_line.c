/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:34:15 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 15:26:41 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_ln(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_store_backup(char **backup)
{
	size_t	i;
	size_t	ln;
	size_t	after_ln;
	char	*next_line;

	if (!(*backup))
		return (NULL);
	i = 0;
	ln = ft_strlen_ln(*backup);
	if (!(*backup)[ln])
	{
		ft_free_backup(backup);
		return (NULL);
	}
	after_ln = ft_stringlen(*backup) - (ln++);
	next_line = ft_calloc((after_ln + 1), sizeof(char), backup);
	if (!next_line)
		return (NULL);
	while ((*backup)[ln] != '\0')
		next_line[i++] = (*backup)[ln++];
	if (*backup)
		ft_free_backup(backup);
	return (next_line);
}

char	*ft_create_line(char **backup)
{
	char	*result;
	size_t	ln;
	size_t	i;

	i = 0;
	if (!(*backup) || !(*backup)[0])
		return (NULL);
	ln = ft_strlen_ln(*backup);
	if ((*backup)[ln] == '\n')
		ln += 1;
	result = ft_calloc(ln + 1, sizeof(char), backup);
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen_ln(*backup))
	{
		result[i] = (*backup)[i];
		i++;
	}
	if ((*backup)[i] == '\n')
		result[i] = '\n';
	return (result);
}

char	*ft_read_line(int fd, char **backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	if (!(*backup))
		(*backup) = ft_calloc(1, sizeof(char), backup);
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		buffer[read_size] = '\0';
		(*backup) = ft_strjoin_str(backup, buffer);
		if (!(*backup))
			return (NULL);
		if (ft_check_ln(buffer) == 1)
			return (*backup);
	}
	return (*backup);
}

int	get_next_line(int fd, char **command)
{
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		ft_free_backup(&backup);
		return (0);
	}
	backup = ft_read_line(fd, &backup);
	if (!backup)
		return (0);
	(*command) = ft_create_line(&backup);
	if (!(*command))
	{
		if (backup)
			ft_free_backup(&backup);
		return (0);
	}
	backup = ft_store_backup(&backup);
	return (1);
}
