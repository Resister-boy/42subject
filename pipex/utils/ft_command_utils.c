/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:47:46 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 17:03:44 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_find_cmd(char *envp, t_pipe *pip)
{
	size_t	i;
	t_cmd	*cmds;
	char	*cmd_path;

	cmds = (pip->cmds);
	(pip->paths) = ft_split(ft_substr(envp, 5, ft_strlen(envp)), ':');
	while (cmds != NULL)
	{
		i = 0;
		while ((pip->paths)[i])
		{
			cmd_path = ft_strjoin((pip->paths)[i], cmds->cmd);
			if (ft_check_executable(cmd_path))
				printf("True\n");
			else
				printf("False\n");
			i++;
		}
		free(cmd_path);
		cmds = cmds->next;
	}
}

void	ft_find_path(char **envp, t_pipe *pip)
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
	ft_find_cmd(envp[i], pip);
}

void	ft_store_cmd(int argc, char **argv, t_pipe *pip)
{
	int		i;
	char	*cmd;
	char	*option;

	i = 2;
	option = NULL;
	while (i < (argc - 1))
	{
		if (argv[i][0] != '-')
		{
			cmd = argv[i];
			if (argv[i + 1][0] == '-')
				option = argv[i + 1];
			ft_lstadd_back(&(pip->cmds), ft_lstnew(cmd, option));
		}
		i++;
	}
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
