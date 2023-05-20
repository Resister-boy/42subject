/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 20:17:53 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_pipe	*get_lastnode(t_pipe_manager *p_manager)
{
	t_pipe	*cur;

	if (p_manager->head == NULL)
		return (NULL);
	cur = p_manager->head;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

int	fill_content(char *cmds, t_pipe *pipe, char **envp)
{
	size_t	i;
	t_io	*redir;
	int		quote[2];

	i = 0;
	redir = NULL;
	while (cmds[i])
	{
		if (cmds[i] == '<')
			i = parse_in_redir(cmds, i, &redir);
		else if (cmds[i] == '>')
			i = parse_out_redir(cmds, i, &redir);
	}
}

void	create_pipe_list(t_pipe_manager *p_manager, char *cmds, char **envp)
{
	t_pipe	*new;
	t_pipe	*last;

	if (envp == NULL || cmds == NULL)
		return ;
	new = (t_pipe *)malloc(sizeof(t_pipe));
	new->test = ft_strdup(cmds);
	fill_content(cmds, &new);
	last = get_lastnode(p_manager);
	if (last == NULL)
		p_manager->head = new;
	else
		last->next = new;
}
