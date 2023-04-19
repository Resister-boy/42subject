#include "./../so_long.h"

int ft_is_map_square(t_map *map)
{
	size_t	w_len;

	w_len = ft_strlen(map->map_line);
	while (map->next != NULL)
	{
		if (ft_strlen(map->map_line) != w_len)
			return (0);
		map = map->next;
	}
	return (1);
}

int	ft_is_size_enough(t_map *map)
{
	size_t	w_len;
	size_t	h_len;

	w_len = ft_strlen(map->map_line);
	h_len = 0;
	while (map != NULL)
	{
		h_len++;
		map = map->next;
	}
	if ((w_len * h_len) < 12)
		return (0);
	return (1);
}

int	ft_is_rounded_wall(t_map *map)
{
	while (map != NULL)
	{
		if (map->prev == NULL || map->next == NULL)
		{
			if (ft_is_all_wall(map->map_line) == 0)
				return (0);
		}
		else if (ft_is_both_end_wall(map->map_line) == 0)
			return (0);
		map = map->next;
	}
	return (1);
}

int	ft_is_other_symbol(t_map *map)
{
	size_t	i;
	char	*line;

	while (map != NULL)
	{
		i = 0;
		line = map->map_line;
		while (line[i])
		{
			if (line[i] != '1' && line[i] != 'E' && line[i] != 'C' \
			&& line[i] != 'P' && line[i] != '0' && line[i] != '\n')
				return (0);
			i++;
		}		
		map = map->next;
	}
	return (1);
}

int	ft_is_symbol_ok(t_stat *stat)
{
	size_t	i;
	char	*line;
	t_map	*map;

	map = stat->map;
	while (map != NULL)
	{
		i = 0;
		line = map->map_line;
		while (line[i])
		{
			ft_count_flag(stat, line[i]);
			i++;
		}
		map = map->next;
	}
	if (stat->escape > 1 || stat->player > 1)
		return (0);
	return (1);
}