/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:09:04 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:11:13 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_check_map(t_stat *stat)
{
	if (ft_is_map_square(stat) == 0)
		return (-1);
	if (ft_is_size_enough(stat) == 0)
		return (-1);
	if (ft_is_rounded_wall(stat) == 0)
		return (-1);
	if (ft_check_map_symbol(stat) == 0)
		return (-1);
	if (ft_is_map_playable(stat) == 0)
		return (-1);
	return (1);
}

int	ft_is_map_square(t_stat *stat)
{
	size_t	i;
	char	**map;

	i = 0;
	map = stat->map_arr;
	while (i < (stat->map_y))
	{
		if (ft_strlen(map[i]) != stat->map_x)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_size_enough(t_stat *stat)
{
	if (stat->map_x * stat->map_y > 12)
		return (1);
	return (0);
}

int	ft_is_rounded_wall(t_stat *stat)
{
	size_t	i;
	char	**map;

	i = 0;
	map = stat->map_arr;
	while (i < (stat->map_y))
	{
		if (i == 0 || i == stat->map_y - 1)
		{
			if (ft_is_all_wall(map[i]) == 0)
				return (0);
		}
		else if (ft_is_both_end_wall(map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map_symbol(t_stat *stat)
{
	size_t	i;
	char	**map;

	i = 0;
	map = stat->map_arr;
	while (i < (stat->map_y))
	{
		if (ft_check_symbol_utils(stat, map[i], i) == 0)
			return (0);
		i++;
	}
	if ((stat->escape) != 1 || (stat->player) != 1)
		return (0);
	return (1);
}
