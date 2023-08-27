/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:12:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:09:40 by jaehulee         ###   ########.fr       */
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

int	get_tmpsize(t_pipe *node)
{
	int		len;
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

void	get_temp(char *str, t_pipe *node)
{
	t_tmp	*tmp;
	t_tmp	*last;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	if (!str)
		tmp->args = ft_strdup("");
	else
		tmp->args = ft_strdup(str);
	tmp->next = NULL;
	last = get_lasttmp(node);
	if (!last)
		node->temp = tmp;
	else
		last->next = tmp;
}
