/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:47:46 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 13:31:22 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_find_cmd(char *envp, t_pipe *pipe)
{
	size_t	i;
	size_t	j;
	t_cmd	*cmds;
	char	*cmd_path;

	i = 0;
	cmds = (pipe->cmds);
	(pipe->paths) = ft_split(ft_substr(envp, 5, ft_strlen(envp)), ':');
	while (i < (pipe)->cmd_count)
	{
		j = 0;
		while ((pipe->paths)[j])
		{
			cmd_path = ft_strjoin((pipe->paths)[j], "/ls");
			printf("cmd_path: %s\n", cmd_path);
			if (ft_check_executable(cmd_path))
				printf("True\n");
			else
				printf("False\n");
			j++;
		}
		free(cmd_path);
		cmds = cmds->next;
	}
}

void	ft_find_path(char **envp, t_pipe *pipe)
{
	size_t	i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_substr(envp[i], 0, 4);
		if (ft_strncmp(path, "PATH", 4) == 1)
		{
			free(path);
			break ;
		}
		free(path);
		i++;
	}
	printf("%s\n", path);
	printf("%s\n", envp[i]);
	ft_find_cmd(envp[i], pipe);
}

void	ft_store_cmd(int argc, char **argv, t_pipe *pipe)
{
	int		i;
	char	*cmd;

	i = 2;
	while (i < (argc - 1))
	{
		if (argv[i + 1][0] == '-')
		{
			cmd = ft_strjoin(argv[i], ft_strjoin(" ", argv[i + 1]));
			i += 2;
		}
		else
		{
			cmd = argv[i];
			i++;
		}
		ft_lstadd_back(&(pipe->cmds), ft_lstnew(cmd));
	}
	pipe->cmd_count = i;
}

int	ft_check_executable(char *cmd_path)
{
	printf("F_OK: %d\n", access(cmd_path, F_OK));
	if (!access(cmd_path, F_OK))
	{
		printf("X_OK: %d\n", access(cmd_path, X_OK));
		if (!access(cmd_path, X_OK))
			printf("Successfully Work!\n");
		else
		{
			ft_print_error(ERROR_CMD_UNEXECUTABLE);
			return (0);
		}
	}
	else
	{
		ft_print_error(ERROR_CMD_NOT_EXIST);
		return (0);
	}
	return (1);
}
