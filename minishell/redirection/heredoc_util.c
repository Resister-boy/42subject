/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:38:47 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 07:39:00 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_heredoc_filename(int i)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(ft_itoa(i), ".mine");
	result = ft_strjoin("/tmp/", temp);
	free(temp);
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
	free(result);
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
	free(result);
	return (fd);
}
