/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:46:45 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/10 17:57:55 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

size_t	get_tmpsize(t_pipe *node)
{
	size_t	len;
	t_tmp	*cur;

	len = 0;
	cur = node->temp;
	if (!cur)
		return (0);
	while (cur)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}
