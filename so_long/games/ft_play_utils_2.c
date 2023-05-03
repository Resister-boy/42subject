/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 04:07:03 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/03 16:13:05 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_finish_game(t_stat *stat)
{
	ft_free_map_arr(stat, &(stat->map_arr));
	mlx_destroy_window(stat->mlx_ptr, stat->win_ptr);
	exit(0);
}

int	ft_is_wall(t_stat *stat, int p_y, int p_x)
{
	char	**map;

	map = stat->map_arr;
	if (map[p_y][p_x] == '1')
		return (1);
	return (0);
}

int	ft_check_escapable(t_stat *stat)
{
	if ((stat->collection) == 0)
		return (1);
	return (0);
}

void	ft_is_not_escape(t_stat *stat, int p_y, int p_x)
{
	int		cur_x;
	int		cur_y;
	char	**map;

	map = stat->map_arr;
	cur_x = stat->p_location.x;
	cur_y = stat->p_location.y;
	if (map[cur_y][cur_x] != 'E')
		map[cur_y][cur_x] = '0';
	ft_render_all_img(stat, cur_y, cur_x);
	map[p_y][p_x] = 'P';
	stat->p_location.y = p_y;
	stat->p_location.x = p_x;
	ft_render_all_img(stat, p_y, p_x);
	(stat->move)++;
}

void	ft_not_allow_escape(t_stat *stat, int p_y, int p_x)
{
	int		cur_x;
	int		cur_y;
	char	**map;

	map = stat->map_arr;
	cur_x = stat->p_location.x;
	cur_y = stat->p_location.y;
	map[cur_y][cur_x] = '0';
	ft_render_all_img(stat, cur_y, cur_x);
	map[p_y][p_x] = 'E';
	stat->p_location.y = p_y;
	stat->p_location.x = p_x;
	ft_render_all_img(stat, p_y, p_x);
	ft_render_single_img(stat, stat->p_img, 1);
	(stat->move)++;
}
