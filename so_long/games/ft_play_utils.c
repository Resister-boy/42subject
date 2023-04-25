/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:20:39 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 19:45:25 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_draw_total_map(t_stat *stat)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = 0;
	map = stat->map_arr;
	while (i < (stat->map_y))
	{
		j = 0;
		while (j < (stat->map_x))
		{
			ft_render_img(stat, i, j);
			j++;
		}
		i++;
	}
}

void	ft_render_img(t_stat *stat, size_t row, size_t col)
{
	mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->g_img, \
	col * 32, row * 32);
	if ((stat->map_arr)[row][col] == 'E')
		mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->e_img, \
		col * 32, row * 32);
	else if ((stat->map_arr)[row][col] == 'P')
		mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->p_img, \
		col * 32, row * 32);
	else if ((stat->map_arr)[row][col] == 'C')
		mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->c_img, \
		col * 32, row * 32);
	else if ((stat->map_arr)[row][col] == '1')
		mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->w_img, \
		col * 32, row * 32);
}
