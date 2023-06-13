/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:39:52 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 17:42:03 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_prompt(t_pipe_manager *p_man, t_env_manager *e_man, char *prompt)
{
	size_t	i;
	int		status;
	t_pipe	*last;

	i = 0;
	status = 0;
	while (prompt[i])
	{
		if (is_valid_pipe(prompt, &i, status))
			last = create_pipe_node(p_man, e_man);
		status = check_quote(prompt[i], status);
		if (status == NO_QUOTE)
			i = parse_no_q(last, e_man, prompt, i);
		else if (status == SINGLE_QUOTE)
			i = parse_single_q(last, prompt, i);
		else if (status == DOUBLE_QUOTE)
			i = parse_double_q(last, e_man, prompt, i);
	}
	(last->cmds) = change_cmds(last, e_man);
	return (1);
}


int	parse_no_q(t_pipe *node, t_env_manager *e_man, char *prompt, size_t idx)
{
	while (prompt[idx] && ft_isspace(prompt[idx]))
		idx++;
	while (prompt[idx] && !ft_isspace(prompt[idx]) && prompt[idx] != '\'' && \
	prompt[idx] != '\"')
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

int	parse_single_q(t_pipe *node, char *prompt, size_t idx)
{
	t_tmp	*new;
	size_t	start;

	idx++;
	start = idx;
	while (prompt[idx] && prompt[idx] != '\'')
		idx++;
	new = (t_tmp *)malloc(sizeof(t_tmp));
	(new->args) = ft_substr(prompt, start, idx - start);
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	idx++;
	return (idx);
}

int	parse_double_q(t_pipe *node, t_env_manager *e_man, char *prompt, size_t idx)
{
	size_t	start;
	t_tmp	*new;
	char	*str;

	idx++;
	start = idx;
	while (prompt[idx] && prompt[idx] != '\"')
		idx++;
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
	idx++;
	return (idx);
}
