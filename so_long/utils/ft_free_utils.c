/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:07:53 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:15:48 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_free_map_list(t_stat	*stat)
{
	t_map	*map;
	t_map	*temp;

	if (stat->map_list == NULL)
		return ;
	map = stat->map_list;
	while (map != NULL)
	{
		temp = map->next;
		free(map->map_line);
		free(map);
		map = temp;
	}
	free(map);
}

void	ft_free_map_arr(t_stat *stat, char **strs)
{
	size_t	i;

	i = 0;
	while (i < (stat->map_y))
	{
		strs[i] = NULL;
		free(strs[i]);
		i++;
	}
	free(strs);
}
