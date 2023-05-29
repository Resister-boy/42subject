/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:34:06 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:40:40 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tmps(t_pipe *node)
{
	t_tmp	*cur;
	t_tmp	*tmp;

	cur = node->temp;
	while (cur)
	{
		tmp = cur->next;
		free(cur->args);
		free(cur);
		cur = tmp;
	}
	node->temp = NULL;
}
