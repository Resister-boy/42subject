#include "./../so_long.h"

int ft_is_map_playable(t_stat *stat)
{
	int		player_x;
	int		player_y;
	char	**c_map;

	player_x = stat->p_location.x;
	player_y = stat->p_location.y;
	c_map = ft_strsdup(stat);
	printf("player_x: %d\n", player_x);
	printf("player_y: %d\n", player_y);
	if (ft_search_map(stat, c_map, player_y, player_x) == 0)
	{
		ft_free_map_arr(stat, c_map);
		return (0);
	}
	ft_free_map_arr(stat, c_map);
	return (1);
}

int	ft_search_map(t_stat *stat, char **map, int p_y, int p_x)
{
	if (map[p_y][p_x] == 'E' || map[p_y][p_x] == 'C' || map[p_y][p_x] == 'P' || map[p_y][p_x] == '0')
		map[p_y][p_x] = '1';
	if (map[p_y - 1][p_x] != '1')
		ft_search_map(stat, map, p_y - 1, p_x);
	if (map[p_y][p_x + 1] != '1')
		ft_search_map(stat, map, p_y, p_x + 1);
	if (map[p_y + 1][p_x] != '1')
		ft_search_map(stat, map, p_y + 1, p_x);
	if (map[p_y][p_x - 1] != '1')
		ft_search_map(stat, map, p_y, p_x - 1);
	if (ft_search_util(stat, map) == 0)
		return (0);
	return (1);
}

int	ft_search_util(t_stat *stat, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (stat->map_y))
	{
		j = 0;
		while (j < (stat->map_x))
		{
			if (map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}