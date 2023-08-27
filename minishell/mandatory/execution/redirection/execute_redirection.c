/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:38:54 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 15:55:41 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_heredoc(t_pipe_manager *p_man, \
	t_env_manager *env_manager, int *is_sigint)
{
	t_pipe	*temp;
	t_io	*temp_redir;

	temp = p_man->head;
	while (temp)
	{
		temp->here_doc_cnt = 0;
		temp_redir = temp->redir;
		while (temp_redir)
		{
			if ((temp_redir->type == REDIR_HEREDOC || \
				temp_redir->type == REDIR_HEREDOC_QUOTE) && *is_sigint == 0)
			{
				if (temp->in_fd != 0)
					close(temp->in_fd);
				temp->in_fd = ft_heredoc(temp_redir, \
					temp->here_doc_cnt, env_manager, is_sigint);
				temp->here_doc_cnt++;
			}
			temp_redir = temp_redir->next;
		}
		temp = temp->next;
	}
	return (0);
}

static int	get_outfile_fd(int *fd, int type, char *filename)
{
	if (*fd != 0)
		close(*fd);
	if (type == REDIR_OUTPUT)
		*fd = output_redirection(filename);
	else if (type == REDIR_APPEND)
		*fd = append_redirection(filename);
	if (*fd == -1)
	{
		ft_perror_join("minishell: ", filename);
		return (1);
	}
	return (0);
}

static int	get_redirection_fd(t_pipe *pipe, t_io *redir)
{
	if (redir->type == REDIR_AMBIGUOUS)
		return (ft_printf(2, "minishell: %s: ambiguous redirect\n", \
			redir->filename) || 1);
	if (redir->type == REDIR_HEREDOC)
		pipe->here_doc_cnt--;
	else if (redir->type == REDIR_INPUT)
	{
		if (access(redir->filename, F_OK | R_OK))
		{
			ft_perror_join("minishell: ", redir->filename);
			return (1);
		}
		else if (!pipe->here_doc_cnt)
		{
			if (pipe->in_fd != 0)
				close(pipe->in_fd);
			pipe->in_fd = input_redirection(redir->filename);
		}
	}
	else
		return (get_outfile_fd(&pipe->out_fd, redir->type, redir->filename));
	return (0);
}

int	execute_redirection(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	t_pipe	*temp;
	t_io	*temp_redir;
	int		is_sigint;

	is_sigint = 0;
	execute_heredoc(p_man, env_manager, &is_sigint);
	if (is_sigint)
		return (1);
	temp = p_man->head;
	while (temp)
	{
		temp_redir = temp->redir;
		while (temp_redir)
		{
			if (get_redirection_fd(temp, temp_redir))
			{
				temp->is_redir_error = 1;
				break ;
			}
			temp_redir = temp_redir->next;
		}
		temp = temp->next;
	}
	return (0);
}
