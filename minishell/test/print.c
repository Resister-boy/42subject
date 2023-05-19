/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:45:55 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 17:19:30 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	print_pipe(t_pipe_manager *p_manager)
{
	t_pipe	*pipe;

	pipe = p_manager->head;
	while (pipe != NULL)
	{
		// printf("%s\n", (pipe->test));
		print_redir(pipe);
		pipe = pipe->next;
	}
}

void	print_redir(t_pipe *pipe)
{
	t_io	*re;

	re = pipe->redir;
	while (re != NULL)
	{
		printf("%s\n", (re->filename));
		printf("%d\n", (re->type));
		re = re->next;
	}
}
