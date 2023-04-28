/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:17:45 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/28 05:31:02 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

char	**ft_strsdup(t_stat *stat)
{
	size_t	i;
	char	**map;
	char	**strs;

	i = 0;
	map = stat->map_arr;
	strs = (char **)malloc(sizeof(char *) * (stat->map_y + 1));
	strs[stat->map_y - 1] = NULL;
	while (i < (stat->map_y))
	{
		strs[i] = ft_strdup(map[i]);
		i++;
	}
	return (strs);
}
