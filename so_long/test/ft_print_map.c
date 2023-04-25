/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:57:26 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:57:33 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_print_map_list(t_stat *stat)
{
	t_map	*map;

	map = stat->map_list;
	while (map != NULL)
	{
		printf("%s", map->map_line);
		map = map->next;
	}
}

void	ft_print_map_arr(t_stat *stat, char **strs)
{
	char	**map;
	size_t	i;

	i = 0;
	map = stat->map_arr;
	while (i < (stat->map_y))
	{
		printf("%s", strs[i]);
		i++;
	}
}
