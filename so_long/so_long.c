/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:29:37 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/20 05:14:15 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_init_stat(t_stat *stat, char *filename)
{
	stat->fd = open(filename, O_RDONLY);
	if (stat->fd <= 0)
		return (0);
	stat->map_list = NULL;
	stat->map_arr = NULL;
	stat->map_size = 0;
	stat->map_x = 0;
	stat->map_y = 0;
	stat->win_width = 0;
	stat->win_height = 0;
	stat->move = 0;
	stat->ground = 0;
	stat->wall = 0;
	stat->collection = 0;
	stat->escape = 0;
	stat->player = 0;
	stat->t_collection = 0;
	stat->t_escape = 0;
	return (1);
}

void	so_long(t_stat *stat)
{
	int	is_collect_map;

	ft_parse_map(stat);
	ft_translate_arr(stat);
	is_collect_map = ft_check_map(stat);
	if (is_collect_map == -1)
	{
		ft_print_message("Error\n");
		ft_free_map_arr(stat, stat->map_arr);
		exit(0);
	}
	printf("\n\nsuccessfully work!\n");
}

int	main(void)
{
	t_stat		stat;
	char		*filename;

	filename = "./map/map_non_playable_3.ber";
	if (ft_is_collect_file(filename) == 0)
	{
		ft_print_message("Error\n");
		return (0);
	}
	if (ft_init_stat(&stat, filename) == 0)
		return (0);
	so_long(&stat);
}