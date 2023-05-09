/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:03:26 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 12:16:03 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_init_pipe(t_pipe *pipe)
{
	pipe->cmd_count = 0;
	pipe->paths = NULL;
}

int	pipex(char **envp, t_pipe *pipe)
{
	ft_find_path(envp, pipe);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;

	if (argc < 5)
		return (0);
	pipe = (t_pipe *)malloc(sizeof(t_pipe));
	ft_init_pipe(pipe);
	ft_store_cmd(argc, argv, pipe);
	ft_print_cmd(pipe);
	pipex(envp, pipe);
	return (1);
}
