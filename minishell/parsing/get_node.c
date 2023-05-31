/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/31 15:41:19 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	init_pipe_node(t_pipe *node)
{
	if (!node)
		return ;
	node->cmds = NULL;
	node->next = NULL;
	node->redir = NULL;
	node->temp = NULL;
}

static int	is_valid_pipe(char *prompt, size_t *idx, int status)
{
	if ((*idx) == 0)
		return (1);
	if (status == NO_QUOTE)
	{
		while (prompt[(*idx)] && prompt[(*idx)] == ft_isspace(prompt[(*idx)]))
			(*idx)++;
		if (prompt[(*idx) + 1] == '|')
			return (1);
	}
	return (0);
}

static t_pipe	*create_pipe_node(t_pipe_manager *p_man, char **envp)
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
		last->cmds = change_cmds(last, envp);
		last->next = new;
	}
	return (new);
}

int	parse_prompt(t_pipe_manager *p_man, char **envp, char *prompt)
{
	size_t	i;
	int		status;
	t_pipe	*last;

	i = 0;
	status = 0;
	if (!envp)
		return (0);
	while (prompt[i])
	{
		if (is_valid_pipe(prompt, &i, status))
			last = create_pipe_node(p_man, envp);
		if (check_quote(prompt[i], &status) == NO_QUOTE)
			i = parse_no_q(last, prompt, i);
		else if (check_quote(prompt[i], &status) == SINGLE_QUOTE)
			i = parse_single_q(last, prompt, i);
		else if (check_quote(prompt[i], &status) == DOUBLE_QUOTE)
			i = parse_double_q(last, prompt, i);
	}
	(last->cmds) = change_cmds(last, envp);
	return (1);
}
