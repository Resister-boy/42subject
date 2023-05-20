/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:47:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:15:50 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	parsing(char *prompt, char **envp)
{
	size_t			i;
	char			**cmds;
	t_pipe_manager	*p_manager;

	i = 0;
	cmds = ft_split(prompt, '|');
	p_manager = (t_pipe_manager *)malloc(sizeof(t_pipe_manager));
	(p_manager->len) = 0;
	(p_manager->head) = NULL;
	printf("cmds_len: %zu\n", ft_strslen(cmds));
	while (i < ft_strslen(cmds))
	{
		create_pipe_list(p_manager, cmds[i], envp);
		(p_manager->len)++;
		i++;
	}
	print_pipe(p_manager);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	**c_envp;

	if (argc != 1 || argv[1] != NULL)
		return (0);
	c_envp = ft_strsdup(envp);
	while (1)
	{
		prompt = readline("bash: ");
		if (!parsing(prompt, c_envp))
			return (0);
	}
	return (1);
}
