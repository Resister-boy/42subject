/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:00:08 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 18:48:04 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_empty_prompt(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] && ft_isspace(prompt[i]))
		i++;
	if (prompt[i] == '\0')
		return (-1);
	return (0);
}

int	valid_pipe(char *prompt)
{
	int	i;
	int	len;

	i = 0;
	while (prompt[i] && ft_isspace(prompt[i]))
		i++;
	if (prompt[i] && prompt[i] == '|')
		return (unexpected_token_error("|"));
	len = ft_strlen(prompt) - 1;
	while (prompt[len] && ft_isspace(prompt[len]))
		len--;
	if (prompt[len] == '|')
		return (unexpected_token_error("|"));
	return (0);
}

int	valid_redir(char *cmd, int idx)
{
	while (cmd[idx] && ft_isspace(cmd[idx]))
		idx++;
	if (cmd[idx] == '\0' || cmd[idx] == '|' || cmd[idx] == '>' || \
	cmd[idx] == '<')
	{
		if (cmd[idx] == '\0')
			unexpected_token_error("newline");
		else if (cmd[idx] == '|')
			unexpected_token_error("|");
		else if (cmd[idx] == '>')
			unexpected_token_error(">");
		else if (cmd[idx] == '<')
			unexpected_token_error("<");
		return (1);
	}
	return (0);
}

int	check_valid_quote(char *prompt)
{
	int		i;
	int		status;

	i = 0;
	status = 0;
	while (prompt[i])
	{
		status = check_is_quote(prompt[i], status);
		i++;
	}
	if (status != NO_QUOTE)
	{
		if (status == SINGLE_QUOTE)
			return (unexpected_token_error("\'"));
		else if (status == DOUBLE_QUOTE)
			return (unexpected_token_error("\""));
		return (1);
	}
	return (0);
}
