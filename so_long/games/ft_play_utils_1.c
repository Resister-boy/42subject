/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:20:39 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/28 10:07:35 by jaehulee         ###   ########.fr       */
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
			ft_render_all_img(stat, i, j);
			j++;
		}
		i++;
	}
}

void	ft_render_single_img(t_stat *stat, void *img, int flag)
{
	int	p_y;
	int	p_x;

	p_y = stat->p_location.y;
	p_x = stat->p_location.x;
	mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->g_img, \
	p_x * 32, p_y * 32);
	if (flag == 1)
		mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, stat->e_img, \
		p_x * 32, p_y * 32);
	mlx_put_image_to_window(stat->mlx_ptr, stat->win_ptr, img, p_x * 32, \
	p_y * 32);
}

void	ft_render_all_img(t_stat *stat, int row, int col)
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

int	ft_key_press(int keycode, t_stat *stat)
{
	int	p_y;
	int	p_x;

	p_y = stat->p_location.y;
	p_x = stat->p_location.x;
	if (keycode == KEY_ESC)
		ft_finish_game(stat);
	else if (keycode == KEY_W)
		ft_move_player(stat, p_y - 1, p_x);
	else if (keycode == KEY_S)
		ft_move_player(stat, p_y + 1, p_x);
	else if (keycode == KEY_A)
		ft_move_player(stat, p_y, p_x - 1);
	else if (keycode == KEY_D)
		ft_move_player(stat, p_y, p_x + 1);
	return (0);
}

void	ft_move_player(t_stat *stat, int p_y, int p_x)
{
	char	**map;

	map = stat->map_arr;
	if (ft_is_wall(stat, p_y, p_x) == 1)
		return ;
	if (map[p_y][p_x] == 'C')
		(stat->collection)--;
	if (map[p_y][p_x] == 'E' && ft_check_escapable(stat) == 1)
	{
		ft_render_single_img(stat, stat->p_img, 0);
		(stat->move)++;
		exit(0);
	}
	else if (map[p_y][p_x] == 'E' && ft_check_escapable(stat) == 0)
		ft_not_allow_escape(stat, p_y, p_x);
	else
		ft_is_not_escape(stat, p_y, p_x);
}
