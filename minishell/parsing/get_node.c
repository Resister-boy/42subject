/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:54:26 by jaehulee         ###   ########.fr       */
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

static void	create_pipe_node(t_pipe_manager *p_man)
{
	t_pipe	*new;
	t_pipe	*last;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	new->cmds = NULL;
	new->next = NULL;
	new->redir = NULL;
	new->temp = NULL;
	last = get_lastnode(p_man);
	if (last == NULL)
		p_man->head = new;
	else
		last->next = new;
}

static void	get_content(t_pipe_manager *p_man, char **envp, t_io *r_list)
{
	t_pipe	*last;

	last = get_lastnode(p_man);
	if (r_list)
		last->redir = r_list;
	else
		last->redir = NULL;
	if (last->temp)
		last->cmds = change_cmds(last, envp);
	else
		last->cmds = NULL;
}

int	parse_prompt(t_pipe_manager *p_man, char **envp, char *prompt)
{
	size_t	i;
	size_t	len;
	int		status;
	t_io	*redir;

	i = 0;
	status = 0;
	len = ft_strlen(prompt);
	redir = NULL;
	while (prompt[i])
	{
		if (is_valid_pipe(prompt, &i, status))
			create_pipe_node(p_man);
		if (check_quote(prompt[i], &status) == NO_QUOTE)
			i = parse_no_q(p_man, prompt, i, &redir);
		else if (check_quote(prompt[i], &status) == SINGLE_QUOTE)
			i = parse_single_q(p_man, prompt, i);
		else if (check_quote(prompt[i], &status) == DOUBLE_QUOTE)
			i = parse_double_q(p_man, prompt, i);
		if (i == len || is_valid_pipe(prompt, &i, status))
			get_content(p_man, envp, redir);
	}
	return (1);
}
