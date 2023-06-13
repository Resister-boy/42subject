/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:42:25 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 17:43:18 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_pipe_node(t_pipe *node)
{
	if (!node)
		return ;
	node->cmds = NULL;
	node->next = NULL;
	node->redir = NULL;
	node->temp = NULL;
}

t_pipe	*get_lastnode(t_pipe_manager *p_man)
{
	t_pipe	*cur;

	cur = p_man->head;
	if (!cur)
		return (NULL);
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_pipe	*create_pipe_node(t_pipe_manager *p_man, t_env_manager *e_man)
{
	t_pipe	*new;
	t_pipe	*last;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	init_pipe_node(new);
	last = get_lastnode(p_man);
	if (last == NULL)
		p_man->head = new;
	else
	{
		last->cmds = change_cmds(last, e_man);
		last->next = new;
	}
	return (new);
}

int	is_valid_pipe(char *prompt, size_t *idx, int status)
{
	if ((*idx) == 0)
		return (1);
	if (status == NO_QUOTE)
	{
		while (prompt[(*idx)] && ft_isspace(prompt[(*idx)]))
			(*idx)++;
		if (prompt[(*idx)] == '|')
		{
			(*idx)++;
			return (1);
		}
	}
	return (0);
}