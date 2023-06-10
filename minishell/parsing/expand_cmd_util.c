/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:02:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 18:03:34 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*expand_env_cmd(t_env_manager *e_man, char *str)
{
	t_env	*expanded;

	expanded = get_env(e_man->head, str);
	return (expanded);
}

void	connect_cmd_tmp(char *cmd, t_pipe *node)
{
	size_t	i;
	char	**n_buf;

	i = 0;
	if (!is_all_space(cmd))
		get_temp(cmd, node);
	else
	{
		n_buf = ft_split(cmd, ' ');
		while (n_buf[i])
		{
			get_temp(n_buf[i], node);
			i++;
		}
	}
}
