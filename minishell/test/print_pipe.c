/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:05:59 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 18:58:48 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	print_pipe(t_pipe_manager *p_man)
{
	t_pipe	*node;

	node = p_man->head;
	while (node)
	{
		print_redir(node);
		print_cmd(node);
		node = node->next;
	}
}


void	print_redir(t_pipe *node)
{
	t_io	*cur;

	cur = node->redir;
	if (!cur)
		printf("No redirection!\n");
	else
	{
		while (cur->next)
		{
			printf("type: %d\n", cur->type);
			printf("filename: %s\n", cur->filename);
			cur = cur->next;
		}
	}
}

void	print_cmd(t_pipe *node)
{
	size_t	i;
	t_cmd	*cmd;
	char	**strs;

	i = 0;
	cmd = node->cmd;
	if (!cmd)
		printf("No commands!\n");
	else
	{
		strs = cmd->args;
		while (strs[i])
		{
			printf("cmd: %s\n", strs[i]);
			i++;
		}
	}
}
