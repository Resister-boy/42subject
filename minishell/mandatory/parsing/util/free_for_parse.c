/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:20:18 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 18:38:03 by jaehulee         ###   ########.fr       */
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
		ft_free((void **)&tmp->args);
		ft_free((void **)&tmp);
	}
}

void	free_redir(t_io *redir)
{
	ft_free((void **)&redir->temp);
	ft_free((void **)&redir->filename);
}

void	free_all_redir(t_io *redir)
{
	t_io	*temp;

	while (redir)
	{
		temp = redir;
		redir = redir->next;
		free_redir(temp);
		ft_free((void **)&temp);
	}
}

void	free_double_str(char ***strs)
{
	int	i;

	i = 0;
	if (!(strs) || !(*strs))
		return ;
	while ((*strs)[i])
		ft_free((void **)(*strs) + i++);
	ft_free_2dim((void ***)strs);
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
		ft_free((void **)&tmp);
	}
	ft_memset(p_man, 0, sizeof(t_pipe_manager));
}
