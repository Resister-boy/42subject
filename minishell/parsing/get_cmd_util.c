/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 05:08:33 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:11:30 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

static char	*get_cmd_path(char **paths, char *str)
{
	size_t	i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], str);
		if (!access(path, F_OK))
			return (paths[i]);
		i++;
	}
	return (NULL);
}

char	*get_env_path(char **envp, char *str)
{
	char	*path;
	char	**paths;
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	paths = ft_split(envp[i], ':');
	path = get_cmd_path(paths, ft_strjoin("/", str));
	if (!path)
		return (str);
	return (path);
}
