/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:58:22 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 19:22:59 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_redir(t_io *redir)
{
	if (!redir)
	{
		redir->filename = NULL;
		redir->temp = NULL;
	}
}

void	connect_redir(t_pipe *node, t_env_manager *e_man, t_io *cur_redir)
{
	t_io	*cur;
	char	*file;

	file = cur_redir->temp;
	if (check_quote_include(file) && cur_redir->type == REDIR_HEREDOC)
		cur_redir->type = REDIR_HEREDOC_QUOTE;
	if (check_dollar(file) && cur_redir->type != REDIR_HEREDOC \
	&& cur_redir->type != REDIR_HEREDOC_QUOTE)
		handle_redir_expand(file, e_man, cur_redir);
	else
		handle_redir_copy(file, cur_redir);
	cur = get_last_redir(node);
	if (!cur)
		node->redir = cur_redir;
	else
		cur->next = cur_redir;
}

int	parse_out_redir(t_pipe *node, t_env_manager *e_man, char *cmd, int idx)
{
	int		status;
	int		start;
	t_io	*redir;

	status = 0;
	redir = (t_io *)malloc(sizeof(t_io));
	init_redir(redir);
	idx = get_out_redir_content(cmd, redir, idx);
	if ((idx == -1 || check_valid_quote(cmd)) && !ft_free((void **)&redir))
		return (-1);
	while (cmd[idx] && ft_isspace(cmd[idx]) && cmd[idx] != '|')
		idx++;
	start = idx;
	while (cmd[idx] && cmd[idx] != '|')
	{
		status = check_is_quote(cmd[idx], status);
		if (check_status(cmd[idx], status))
			break ;
		idx++;
	}
	redir->temp = ft_substr(cmd, start, idx - start);
	redir->next = NULL;
	connect_redir(node, e_man, redir);
	return (idx);
}

int	parse_in_redir(t_pipe *node, t_env_manager *e_man, char *cmd, int idx)
{
	int		status;
	int		start;
	t_io	*redir;

	status = 0;
	redir = (t_io *)malloc(sizeof(t_io));
	init_redir(redir);
	idx = get_in_redir_content(cmd, redir, idx);
	if ((idx == -1 || check_valid_quote(cmd)) && !ft_free((void **)&redir))
		return (-1);
	while (cmd[idx] && ft_isspace(cmd[idx]) && cmd[idx] != '|')
		idx++;
	start = idx;
	while (cmd[idx] && cmd[idx] != '|')
	{
		status = check_is_quote(cmd[idx], status);
		if (check_status(cmd[idx], status))
			break ;
		idx++;
	}
	redir->temp = ft_substr(cmd, start, idx - start);
	redir->next = NULL;
	connect_redir(node, e_man, redir);
	return (idx);
}
