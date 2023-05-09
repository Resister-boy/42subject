/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:17:15 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 03:18:26 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last_cmd;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_cmd = ft_lstlast(*lst);
		last_cmd->next = new;
	}
}
