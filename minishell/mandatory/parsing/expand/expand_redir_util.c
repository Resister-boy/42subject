/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redir_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:35:32 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:08:21 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir_str_sq(char *str, char **buf, int i, int *j)
{
	int	start;

	start = ++i;
	while (str[i] && str[i] != '\'')
		i++;
	if (start < i)
		buf[(*j)++] = ft_substr(str, start, i - start);
	if (str[i] != '\0')
		i++;
	return (i);
}

int	handle_redir_str_dq(char *str, char **buf, int i, int *j)
{
	int	start;

	start = ++i;
	while (str[i] && str[i] != '\"')
		i++;
	if (start < i)
		buf[(*j)++] = ft_substr(str, start, i - start);
	if (str[i] != '\0')
		i++;
	return (i);
}

int	handle_redir_str_no(char *str, char **buf, int i, int *j)
{
	int	start;

	start = i;
	while (str[i] && str[i] != '\'' && str[i] != '\"')
		i++;
	if (start < i)
		buf[(*j)++] = ft_substr(str, start, i - start);
	return (i);
}
