/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:42:11 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 18:35:51 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_tmp	*get_lasttmp(t_pipe *pipe)
{
	t_tmp	*temp;

	temp = pipe->temp;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	check_quote(char chr, int *status)
{
	if ((*status) == 0 && chr == '\'')
	{
		(*status) = 1;
		return (1);
	}
	else if ((*status) == 0 && chr == '\"')
	{
		(*status) = 2;
		return (2);
	}
	else if (((*status) == 1) && (chr == '\''))
		(*status) = 0;
	else if (((*status) == 2) && (chr == '\"'))
		(*status) = 0;
	return (0);
}

int	parse_no_q(t_pipe_manager *p_man, char *prompt, size_t idx, t_io **r_list)
{
	while (prompt[idx] && !check_space(prompt[idx]))
		idx++;
	while (prompt[idx] && check_space(prompt[idx]) && prompt[idx] != '\'' && \
	prompt[idx] != '\"')
	{
		if (prompt[idx] == '<')
			idx = parse_in_redir(prompt, idx, r_list);
		else if (prompt[idx] == '>')
			idx = parse_out_redir(prompt, idx, r_list);
		else if (prompt[idx] != check_space(prompt[idx]))
			idx = parse_cmd(p_man, prompt, idx);
		idx++;
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
	while (prompt[idx] || prompt[idx] != '\'')
		idx++;
	new = (t_tmp *)malloc(sizeof(t_tmp));
	(new->args) = ft_substr(prompt, start, idx);
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	return (idx);
}

int	parse_double_q(t_pipe_manager *p_man, char *prompt, size_t idx)
{
	t_pipe	*node;
	size_t	start;
	t_tmp	*new;
	char	**buf;

	start = idx;
	node = get_lastnode(p_man);
	while (prompt[idx] || prompt[idx] != '\"')
		idx++;
	buf = ft_split(ft_substr(prompt, start, idx), '$');
	new = (t_tmp *)malloc(sizeof(t_tmp));
	(new->args) = expand_env(buf);
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	return (idx);
}
