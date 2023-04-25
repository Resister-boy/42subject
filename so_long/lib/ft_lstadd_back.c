/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:16:30 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:17:01 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_lstadd_back(t_stat *stat, t_map *new)
{
	t_map	*last;

	if (stat->map_list == NULL)
		stat->map_list = new;
	else
	{
		last = ft_lstlast(stat->map_list);
		last->next = new;
	}
}
