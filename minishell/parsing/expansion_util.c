/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:42 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:34:28 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	get_dollar_count(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] || str[i + 1] != '$'))
			count++;
		i++;
	}
	return (count);
}

void	connect_cmd_tmp(char **buf, t_pipe *node)
{
	size_t	i;
	char	*str;
	char	**n_buf;
	t_tmp	*last;

	i = 0;
	str = total_join(buf);
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
	size_t	j;
	size_t	start;
	size_t	dollar_cnt;

	i = 0;
	dollar_cnt = get_dollar_count(str);
	while (i < dollar_cnt)
	{
		j = 0;
		while (str[j] && str[j] != '$')
			j++;
		if (str[j] == '$')
		{
			start = j++;
			while (str[j] && str[j] != '$')
				j++;
			expand_env(ft_substr(str, start, j - start), node);
		}
		i++;
	}
}
