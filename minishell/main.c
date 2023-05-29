/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:47:01 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 07:55:58 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parsing(t_pipe_manager *p_man, char **envp, char *prompt)
{
	size_t	i;

	i = 0;
	p_man->head = NULL;
	p_man->size = 0;
	parse_prompt(p_man, envp, prompt);
	print_pipe(p_man);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_manager	p_man;
	char			*prompt;

	if (argc != 1 || argv[1] != NULL)
		return (0);
	while (1)
	{
		prompt = readline("minishell: ");
		if (!parsing(&p_man, envp, prompt))
			return (0);
		add_history(prompt);
	}
	return (1);
}
