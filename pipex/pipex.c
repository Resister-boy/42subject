/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:03:26 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 23:12:44 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	ft_init_pipe(t_pipe *pip, int argc, char **argv)
{
	pip->here_doc = ft_check_heredoc(argv[1]);
	pip->cmd_count = argc - 3 - (pip->here_doc);
	if ((pip->here_doc) == 1)
		ft_here_doc(argv[2], pip);
	else
	{
		(pip->fd)[0] = open(argv[1], O_RDONLY);
		if ((pip->fd)[0] < 0)
				ft_print_error(ERROR_INFILE);
	}
	(pip->fd)[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((pip->fd)[1] < 0)
		ft_print_error(ERROR_OUTFILE);
}

int	pipex(char **argv, char **envp, t_pipe *pip)
{
	size_t	i;

	i = 0;
	ft_find_path(envp, pip);
	printf("cmd_count: %zu\n", pip->cmd_count);
	while (i < (pip->cmd_count))
	{
		if (!ft_create_process(argv, pip))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pip;

	if (argc < 5)
		return (0);
	pip = (t_pipe *)malloc(sizeof(t_pipe));
	ft_init_pipe(pip, argc, argv);
	ft_store_cmd(argc, argv, pip);
	ft_print_cmd(pip);
	pipex(argv, envp, pip);
	return (1);
}
