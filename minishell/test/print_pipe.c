/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:05:59 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/12 18:58:48 by seonghle         ###   ########seoul.kr  */
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
		printf("[%s] ", strs[i]);
		i++;
	}
	printf("\n");
}

static char	*get_redir_sign(int type)
{
	if (type == REDIR_INPUT)
		return ("<");
	else if (type == REDIR_HEREDOC)
		return ("<<");
	else if (type == REDIR_OUTPUT)
		return (">");
	else if (type == REDIR_APPEND)
		return (">>");
	else if (type == REDIR_AMBIGUOUS)
		return ("REDIR_AMBIGUOUS");
	return (NULL);
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
			if (cur->type)
				printf("[%s %s] ", get_redir_sign(cur->type), \
				cur->filename);
			cur = cur->next;
		}
	}
	printf("\n");
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
		if (node->next)
			printf("------------------ PIPE! ------------------ \n");
		node = node->next;
		i++;
	}
}
