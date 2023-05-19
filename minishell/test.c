/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/18 20:21:43 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_pipe	*get_lastnode(t_pipe_manager *p_manager)
{
	t_pipe	*cur;

	if (p_maneger->head == NULL)
		return (NULL);
	cur = p_manager->head;
	while (cur == NULL)
		cur = cur->next;
	return (cur);
}

void	get_content(t_pipe *pipe, char *cmds)
{
	pipe->redir = get_redir(pipe, cmds);
	pipe->cmd = get_cmds(pipe, cmds);
	expand_cmds(pipe, cmds);
}

void	create_pipe_list(t_pipe_manager *p_manager, char *cmds, char **envp)
{
	t_pipe	*new;
	t_pipe	*last;

	if (envp == NULL || cmds == NULL)
		return ;
	new = (t_pipe *)malloc(sizeof(t_pipe));
	new->test = ft_strdup(cmds);
	new->next = NULL;
	get_content(new, cmds);
	last = get_lastnode(p_manager);
	if (last == NULL)
		p_manager->head = new;
	else
		last->next = new;
}
