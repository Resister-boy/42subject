/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 18:50:49 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_pipe	*get_lastnode(t_pipe_manager *p_man)
{
	t_pipe	*cur;

	if (p_man->head == NULL)
		return (NULL);
	cur = p_man->head;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

int	is_valid_pipe(char *prompt, size_t idx, int status)
{
	if (idx == 0 || (prompt[idx] == '|' && status == 0))
		return (1);
	return (0);
}

void	create_pipe_node(t_pipe_manager *p_man)
{
	t_pipe	*new;
	t_pipe	*last;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	new->cmd = NULL;
	new->next = NULL;
	new->redir = NULL;
	new->temp = NULL;
	last = get_lastnode(p_man);
	if (last == NULL)
		p_man->head = new;
	else
		last->next = new;
}

void	get_content(t_pipe_manager *p_man, t_io *r_list)
{
	t_pipe	*last;

	last = get_lastnode(p_man);
	if (r_list != NULL)
			last->redir = r_list;
	if (last->temp != NULL)
		last->cmd = change_cmds(last);
}

int	parse_prompt(t_pipe_manager *p_man, char *prompt, char **envp)
{
	size_t	i;
	int		status;
	t_io	*redir;

	i = 0;
	status = 0;
	redir = NULL;
	if (!envp)
		return (0);
	while (prompt[i])
	{
		if (is_valid_pipe(prompt, i, status))
			create_pipe_node(p_man);
		if (check_quote(prompt[i], &status) == 0)
			i = parse_no_q(p_man, prompt, i, &redir);
		else if (check_quote(prompt[i], &status) == 1)
			i = parse_single_q(p_man, prompt, i);
		else if (check_quote(prompt[i], &status) == 2)
			i = parse_double_q(p_man, prompt, i);
		get_content(p_man, redir);
	}
	return (1);
}
