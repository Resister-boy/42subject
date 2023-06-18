/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:58:22 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/12 16:47:53 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_redir(t_io *redir)
{
	if (!redir)
	{
		redir->filename = NULL;
		redir->next = NULL;
		redir->temp = NULL;
	}
}

void	connect_redir(t_pipe *node, t_env_manager *e_man, t_io *cur_redir)
{
	t_io	*cur;
	char	*t_file;

	cur = node->redir;
	t_file = cur_redir->temp;
	if (check_dollar(t_file))
		handle_redir_expand(t_file, e_man, cur_redir);
	else
		cur_redir->filename = ft_strdup(t_file);
	if (!cur)
		node->redir = cur_redir;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = cur_redir;
	}
}

int	parse_out_redir(t_pipe *node, t_env_manager *e_man, char *cmd, size_t idx)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	init_redir(redir);
	if (cmd[(idx) + 1] == '>')
	{
    redir->type = REDIR_APPEND;
		(idx) += 2;
	}
	else
	{
    redir->type = REDIR_OUTPUT;
		(idx) += 1;
	}
	while (cmd[(idx)] && ft_isspace(cmd[idx]))
		(idx)++;
	start = (idx);
	while (cmd[(idx)] && !ft_isspace(cmd[idx]))
		(idx)++;
	redir->temp = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(node, e_man, redir);
	return (idx);
}

int	parse_in_redir(t_pipe *node, t_env_manager *e_man, char *cmd, size_t idx)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	init_redir(redir);
	if (cmd[(idx) + 1] == '<')
	{
    redir->type = REDIR_HEREDOC;
		(idx) += 2;
	}
	else
	{
		redir->type = REDIR_INPUT;
		(idx) += 1;
	}
	while (cmd[idx] && ft_isspace(cmd[idx]))
		(idx)++;
	start = (idx);
	while (cmd[idx] && !ft_isspace(cmd[idx]))
		(idx)++;
	redir->temp = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(node, e_man, redir);
	return (idx);
}
