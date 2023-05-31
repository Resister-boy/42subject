/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:42 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/31 18:20:09 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_dollar(char *str, size_t idx)
{
	if (str[idx] == '$' && str[idx + 1] && (ft_isalpha(str[idx + 1]) \
	|| str[idx + 1] == '_'))
		return (1);
	return (0);
}

size_t	get_dollar_count(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_valid_dollar(str, i))
			count++;
		i++;
	}
	return (count);
}

void	connect_cmd_tmp(char *str, t_pipe *node)
{
	size_t	i;
	char	**n_buf;
	t_tmp	*last;

	i = 0;
	last = get_lasttmp(node);
	if (!is_all_space(str))
		get_temp(str, node);
	else
	{
		n_buf = ft_split(str, ' ');
		while (n_buf[i])
		{
			get_temp(n_buf[i], node);
			i++;
		}
	}	
}

void	handle_expand(char *str, t_pipe *node)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (str[i])
	{
		start = i;
		while (str[i] && str[i] != '$')
			i++;
		if (start < i)
			get_temp(ft_substr(str, start, i - start), node);
		if (is_valid_dollar(str, i))
		{
			i++;
			start = i;
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
			expand_env(ft_substr(str, start, i - start), node);
		}
	}
}
