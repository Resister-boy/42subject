/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:05:59 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/11 01:13:56 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_cmd(t_pipe *node)
{
	size_t	i;
	char	**strs;

	i = 0;
	strs = node->cmds;
	if (!strs)
	{
		printf("No Command!\n");
		return ;
	}
	while (strs[i])
	{
		printf("cmds: %s\n", strs[i]);
		i++;
	}
}

static void	print_redir(t_pipe *node)
{
	t_io	*cur;

	cur = node->redir;
	if (!cur)
		printf("No redirection!\n");
	else
	{
		while (cur)
		{
			printf("type: %d\n", cur->type);
			printf("sign: %s\n", cur->sign);
			printf("filename: %s\n", cur->filename);
			cur = cur->next;
		}
	}
}

void	print_pipe(t_pipe_manager *p_man)
{
	t_pipe	*node;
	size_t	i;

	i = 1;
	node = p_man->head;
	while (node)
	{
		print_redir(node);
		print_cmd(node);
		printf("------------------ %zu PIPE! ------------------ \n")
		node = node->next;
		i++;
	}
}
