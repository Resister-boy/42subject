/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:00:34 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/31 15:42:43 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_no_q(t_pipe *node, char *prompt, size_t idx)
{
	while (prompt[idx] && ft_isspace(prompt[idx]))
		idx++;
	while (prompt[idx] && !ft_isspace(prompt[idx]) && prompt[idx] != '\'' && \
	prompt[idx] != '\"')
	{
		if (prompt[idx] == '<')
			idx = parse_in_redir(node, prompt, idx);
		else if (prompt[idx] == '>')
			idx = parse_out_redir(node, prompt, idx);
		else if (prompt[idx] != ft_isspace(prompt[idx]))
			idx = parse_cmd(node, prompt, idx);
	}
	return (idx);
}

int	parse_single_q(t_pipe *node, char *prompt, size_t idx)
{
	t_tmp	*new;
	size_t	start;

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

int	parse_double_q(t_pipe *node, char *prompt, size_t idx)
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
		expand_env_quote(str, new);
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
