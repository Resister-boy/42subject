/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:59:34 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:01:47 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_last_char(char *prompt, int idx, char quote)
{
	int		status;

	if (quote == '\'')
		status = SINGLE_QUOTE;
	else if (quote == '\"')
		status = DOUBLE_QUOTE;
	while (prompt[idx])
	{
		status = check_is_quote(prompt[idx], status);
		if (prompt[idx] == quote)
			break ;
		idx++;
	}
	if (status == NO_QUOTE && prompt[idx] == '\0')
		return (--idx);
	if (status != NO_QUOTE && prompt[idx] == '\0')
		return (-1);
	return (idx);
}

int	get_out_redir_content(char *cmd, t_io *redir, int idx)
{
	if (cmd[idx + 1] == '>')
	{
		if (cmd[idx + 2] == '>')
		{
			unexpected_token_error(">");
			return (-1);
		}
		redir->type = REDIR_APPEND;
		idx += 2;
	}
	else
	{
		redir->type = REDIR_OUTPUT;
		idx += 1;
	}
	if (valid_redir(cmd, idx))
		return (-1);
	return (idx);
}

int	get_in_redir_content(char *cmd, t_io *redir, int idx)
{
	if (cmd[idx + 1] == '<')
	{
		if (cmd[idx + 2] == '<')
		{
			unexpected_token_error("<");
			return (-1);
		}
		redir->type = REDIR_HEREDOC;
		idx += 2;
	}
	else
	{
		redir->type = REDIR_INPUT;
		idx += 1;
	}
	if (valid_redir(cmd, idx))
		return (-1);
	return (idx);
}

t_io	*get_last_redir(t_pipe *node)
{
	t_io	*cur;

	cur = node->redir;
	if (!cur)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}
