/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/31 16:42:25 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connect_redir(t_pipe *node, t_io *redirection)
{
	t_io	*cur;

	cur = node->redir;
	if (!cur)
		node->redir = redirection;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = redirection;
	}
}

int	parse_out_redir(t_pipe *node, char *cmd, size_t idx)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	if (cmd[(idx) + 1] == '>')
	{
		(redir->type) = REDIR_DOUBLE_OUT;
		(idx) += 2;
	}
	else
	{
		(redir->type) = REDIR_SINGLE_OUT;
		(idx) += 1;
	}
	while (cmd[(idx)] && ft_isspace(cmd[idx]))
		(idx)++;
	start = (idx);
	while (cmd[(idx)] && !ft_isspace(cmd[idx]))
		(idx)++;
	redir->filename = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(node, redir);
	return (idx);
}

int	parse_in_redir(t_pipe *node, char *cmd, size_t idx)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	if (cmd[(idx) + 1] == '<')
	{
		(redir->type) = REDIR_DOUBLE_IN;
		(idx) += 2;
	}
	else
	{
		(redir->type) = REDIR_SINGLE_IN;
		(idx) += 1;
	}
	while (ft_isspace(cmd[idx]))
		(idx)++;
	start = (idx);
	while (!ft_isspace(cmd[idx]))
		(idx)++;
	redir->filename = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(node, redir);
	return (idx);
}
