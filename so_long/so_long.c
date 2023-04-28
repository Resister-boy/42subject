/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:29:37 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/28 07:15:02 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_init_game(t_stat *stat, void *mlx_ptr, void *win_ptr)
{
	int	img_w;
	int	img_y;

	stat->mlx_ptr = mlx_ptr;
	stat->win_ptr = win_ptr;
	stat->p_img = mlx_xpm_file_to_image(mlx_ptr, "./src/doge.xpm", \
	&img_w, &img_y);
	stat->g_img = mlx_xpm_file_to_image(mlx_ptr, "./src/ground.xpm", \
	&img_w, &img_y);
	stat->c_img = mlx_xpm_file_to_image(mlx_ptr, "./src/rocket.xpm", \
	&img_w, &img_y);
	stat->e_img = mlx_xpm_file_to_image(mlx_ptr, "./src/mars.xpm", \
	&img_w, &img_y);
	stat->w_img = mlx_xpm_file_to_image(mlx_ptr, "./src/wall.xpm", \
	&img_w, &img_y);
	ft_draw_total_map(stat);
}

int	ft_init_stat(t_stat *stat, char *filename)
{
	stat->fd = open(filename, O_RDONLY);
	if (stat->fd <= 0)
		return (0);
	stat->map_list = NULL;
	stat->map_arr = NULL;
	stat->map_x = 0;
	stat->map_y = 0;
	stat->move = 0;
	stat->ground = 0;
	stat->wall = 0;
	stat->collection = 0;
	stat->escape = 0;
	stat->player = 0;
	stat->t_collection = 0;
	stat->t_escape = 0;
	stat->p_location.x = 0;
	stat->p_location.y = 0;
	return (1);
}

void	so_long(t_stat *stat)
{
	int		is_collect_map;
	void	*mlx_ptr;
	void	*win_ptr;

	ft_parse_map(stat);
	ft_translate_arr(stat);
	is_collect_map = ft_check_map(stat);
	if (is_collect_map == -1)
	{
		ft_print_message("Error\n");
		ft_free_map_arr(stat, stat->map_arr);
		exit(0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, (stat->map_x) * 32, (stat->map_y) * 32, \
	"so_long");
	ft_init_game(stat, mlx_ptr, win_ptr);
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &ft_key_press, stat);
	mlx_loop(mlx_ptr);
}

int	main(void)
{
	t_stat		stat;
	char		*filename;

	filename = "./map/map_normal.ber";
	if (ft_is_collect_file(filename) == 0)
	{
		ft_print_message("Error\n");
		return (0);
	}
	if (ft_init_stat(&stat, filename) == 0)
		return (0);
	so_long(&stat);
	close(stat.fd);
	printf("\n\nsuccessfully work!\n");
}
