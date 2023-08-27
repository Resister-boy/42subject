/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:39:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 18:35:31 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse_no_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
int idx)
{
	if (prompt[idx] == '\0' || prompt[idx] == '\'' || prompt[idx] == '\"')
		return (idx);
	while (prompt[idx] && ft_isspace(prompt[idx]))
		idx++;
	while (prompt[idx] && !ft_isspace(prompt[idx]))
	{
		if (prompt[idx] == '<')
			idx = parse_in_redir(node, e_man, prompt, idx);
		else if (prompt[idx] == '>')
			idx = parse_out_redir(node, e_man, prompt, idx);
		else if (prompt[idx] != ft_isspace(prompt[idx]))
			idx = parse_cmd(node, e_man, prompt, idx);
		if (idx == -1 || prompt[idx] == '|')
			return (idx);
	}
	return (idx);
}

static int	parse_single_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
int idx)
{
	if (get_last_char(prompt, idx, '\'') == -1)
		return (unexpected_token_error("\'"));
	idx = parse_cmd(node, e_man, prompt, idx);
	if (idx == -1)
		return (-1);
	return (idx);
}

static int	parse_double_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
int idx)
{
	if (get_last_char(prompt, idx, '\"') == -1)
		return (unexpected_token_error("\""));
	idx = parse_cmd(node, e_man, prompt, idx);
	if (idx == -1)
		return (-1);
	return (idx);
}

static int	parse_prompt(t_pipe_manager *p_man, t_env_manager *e_man, \
char *prompt)
{
	int		i;
	t_pipe	*last;
	int		status;

	i = 0;
	last = NULL;
	status = 0;
	while (prompt[i])
	{
		status = check_is_quote(prompt[i], status);
		if (is_valid_pipe(prompt, &i))
			last = create_pipe_node(p_man, e_man);
		if (prompt[i] == '\'')
			i = parse_single_q(last, e_man, prompt, i);
		else if (prompt[i] == '\"')
			i = parse_double_q(last, e_man, prompt, i);
		else
			i = parse_no_q(last, e_man, prompt, i);
		if (i == -1)
			return (1);
	}
	if (last)
		last->cmds = change_cmds(last, e_man);
	return (0);
}

int	parsing(t_pipe_manager *p_man, t_env_manager *env_manager, \
	char *prompt)
{
	if (check_empty_prompt(prompt) || valid_pipe(prompt))
		return (1);
	if (parse_prompt(p_man, env_manager, prompt))
	{
		free_prompt(p_man);
		return (1);
	}
	return (0);
}
