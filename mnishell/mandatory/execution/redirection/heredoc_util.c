/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:38:47 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 15:55:30 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_heredoc_filename(int i)
{
	char	*temp;
	char	*result;
	char	*file_num;

	file_num = ft_itoa(i);
	temp = ft_strjoin(file_num, ".mine");
	ft_free((void **)&file_num);
	result = ft_strjoin("/tmp/", temp);
	ft_free((void **)&temp);
	if (!result)
		return (NULL);
	return (result);
}

int	new_heredoc_open(int i)
{
	int		fd;
	char	*result;

	result = get_heredoc_filename(i);
	if (!result)
		return (-1);
	if (!access(result, F_OK))
		unlink(result);
	fd = open(result, O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_free((void **)&result);
	return (fd);
}

int	heredoc_open(int i)
{
	int		fd;
	char	*result;

	result = get_heredoc_filename(i);
	if (!result)
		return (-1);
	fd = open(result, O_RDWR, 0644);
	ft_free((void **)&result);
	return (fd);
}

int	unlink_temp_file(void)
{
	DIR				*directory;
	struct dirent	*entry;
	char			*comma_pos;
	char			*join;

	directory = opendir("/tmp");
	while (1)
	{
		entry = readdir(directory);
		if (!entry)
			break ;
		comma_pos = ft_strrchr(entry->d_name, '.');
		if (comma_pos && ft_strncmp(comma_pos, ".mine", 6) == 0)
		{
			join = ft_strjoin("/tmp/", entry->d_name);
			unlink(join);
			ft_free((void **)&join);
		}
	}
	closedir(directory);
	return (0);
}
