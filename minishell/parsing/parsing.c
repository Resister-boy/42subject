/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:00:34 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:48:39 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	parse_no_q(t_pipe_manager *p_man, char *prompt, size_t idx, t_io **r_list)
{
	while (prompt[idx] && ft_isspace(prompt[idx]))
		idx++;
	while (prompt[idx] && !ft_isspace(prompt[idx]) && prompt[idx] != '\'' && \
	prompt[idx] != '\"')
	{
		if (prompt[idx] == '<')
			idx = parse_in_redir(prompt, idx, r_list);
		else if (prompt[idx] == '>')
			idx = parse_out_redir(prompt, idx, r_list);
		else if (prompt[idx] != ft_isspace(prompt[idx]))
			idx = parse_cmd(p_man, prompt, idx);
	}
	return (idx);
}

int	parse_single_q(t_pipe_manager *p_man, char *prompt, size_t idx)
{
	t_pipe	*node;
	t_tmp	*new;
	size_t	start;

	start = idx;
	node = get_lastnode(p_man);
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

int	parse_double_q(t_pipe_manager *p_man, char *prompt, size_t idx)
{
	t_pipe	*node;
	size_t	start;
	t_tmp	*new;
	char	*str;

	idx++;
	start = idx;
	node = get_lastnode(p_man);
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
