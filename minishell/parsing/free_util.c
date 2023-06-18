/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:20:18 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/16 13:27:14 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tmp(t_tmp *cur)
{
	t_tmp	*tmp;

	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp->args);
		free(tmp);
	}
}

void	free_redir(t_io *redir)
{
	free(redir->temp);
	free(redir->filename);
}

void	free_all_redir(t_io *redir)
{
	t_io	*temp;

	while (redir)
	{
		temp = redir;
		redir = redir->next;
		free_redir(temp);
		free(temp);
	}
}

void	free_double_str(char ***strs)
{
	size_t	i;

	i = 0;
	if (!(strs) || !(*strs))
		return ;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
}

void	free_prompt(t_pipe_manager *p_man)
{
	t_pipe	*cur;
	t_pipe	*tmp;

	cur = p_man->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		if (tmp->redir)
			free_all_redir(tmp->redir);
		if (tmp->cmds)
			free_double_str(&(tmp->cmds));
		if (tmp->temp)
			free_tmp(tmp->temp);
		free(tmp);
	}
	ft_memset(p_man, 0, sizeof(t_pipe_manager));
}
