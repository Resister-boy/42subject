/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:08:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 20:12:25 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	connect_redir(t_io **r_list, t_io *redir)
{
	t_io	*cur;

	if (!(*r_list))
		(*r_list) = redir;
	else
	{
		cur = (*r_list);
		while (cur->next)
			cur = cur->next;
		cur->next = redir;
	}
}

int	parse_out_redir(char *cmd, size_t idx, t_io **r_list)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	if (cmd[(idx) + 1] == '>')
	{
		(redir->type) = REDIR_DOUBLE_OUT;
		(idx) += 2;
	}
	else if (cmd[(idx) + 1] != '>')
	{
		(redir->type) = REDIR_SINGLE_OUT;
		(idx) += 1;
	}
	while (cmd[(idx)] && cmd[(idx)] == ' ')
		(idx)++;
	start = (idx);
	while (cmd[(idx)] && cmd[(idx)] != ' ')
		(idx)++;
	redir->filename = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(r_list, redir);
	return (idx);
}

int	parse_in_redir(char *cmd, size_t idx, t_io **r_list)
{
	size_t	start;
	t_io	*redir;

	redir = (t_io *)malloc(sizeof(t_io));
	if (cmd[(idx) + 1] == '<')
	{
		(redir->type) = REDIR_DOUBLE_IN;
		(idx) += 2;
	}
	else if (cmd[(idx) + 1] == '<')
	{
		(redir->type) = REDIR_SINGLE_IN;
		(idx) += 1;
	}
	while (cmd[(idx)] == ' ')
		(idx)++;
	start = (idx);
	while (cmd[(idx)] != ' ')
		(idx)++;
	redir->filename = ft_substr(cmd, start, (idx) - start);
	redir->next = NULL;
	connect_redir(r_list, redir);
	return (idx);
}

t_io	*get_redirs(char *cmds)
{
	size_t	i;
	t_io	*redir;

	i = 0;
	redir = NULL;
	while (cmds && cmds[i])
	{
		if (cmds[i] == '<')
			i = parse_in_redir(cmds, i, &redir);
		else if (cmds[i] == '>')
			i = parse_out_redir(cmds, i, &redir);
	}
	return (redir);
}
