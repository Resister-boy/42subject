/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:39:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/20 21:25:34 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

// 따옴표 없는 문자열 파싱
static int	parse_no_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
size_t idx)
{
	if (prompt[idx] && (prompt[idx] == '\'' || prompt[idx] == '\"'))
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
	}
	return (idx);
}

// 작은따옴표 파싱
static int	parse_single_q(t_pipe *node, char *prompt, size_t idx)
{
	t_tmp	*new;
	size_t	start;

	start = ++idx;
	while (prompt[idx] && prompt[idx] != '\'')
		idx++;
	if (start == idx)
		return (++idx);
	new = (t_tmp *)malloc(sizeof(t_tmp));
	(new->args) = ft_substr(prompt, start, idx - start);
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	return (++idx);
}

// 큰따옴표 파싱
static int	parse_double_q(t_pipe *node, t_env_manager *e_man, char *prompt, \
size_t idx)
{
	size_t	start;
	t_tmp	*new;
	char	*str;

	start = ++idx;
	while (prompt[idx] && prompt[idx] != '\"')
		idx++;
	if (start == idx)
		return (++idx);
	new = (t_tmp *)malloc(sizeof(t_tmp));
	str = ft_substr(prompt, start, idx - start);
	if (check_dollar(str))
		quote_cmd_expand(str, e_man, new);
	else
		(new->args) = str;
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	return (++idx);
}

// 파싱 시작부분
int	parse_prompt(t_pipe_manager *p_man, t_env_manager *e_man, char *prompt)
{
	size_t	i;
	t_pipe	*last;
	int		status;

	i = 0;
	last = NULL;
	status = 0;
	while (prompt[i])
	{
		if (is_valid_pipe(prompt, &i, status))
			last = create_pipe_node(p_man, e_man);
		status = check_is_quote(prompt[i], status);
		if (prompt[i] == '\'')
			i = parse_single_q(last, prompt, i);
		else if (prompt[i] == '\"')
			i = parse_double_q(last, e_man, prompt, i);
		else
			i = parse_no_q(last, e_man, prompt, i);
	}
	if (last)
		last->cmds = change_cmds(last, e_man);
	g_exit_status = 0;
	return (1);
}
