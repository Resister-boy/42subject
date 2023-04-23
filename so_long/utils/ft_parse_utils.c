#include "./../so_long.h"

void	ft_translate_arr(t_stat *stat)
{
	size_t	i;
	t_map	*map;
	
	i = 0;
	map = stat->map_list;
	stat->map_y = ft_lstsize(map);
	stat->map_x = ft_strlen(map->map_line);
	stat->map_arr = (char **)malloc(sizeof(char *) * (stat->map_y + 1));
	stat->map_arr[stat->map_y - 1] = NULL;
	while (map != NULL)
	{
		stat->map_arr[i] = ft_strdup(map->map_line);
		map = map->next;
		i++;
	}
	ft_free_map_list(stat);
}

t_map	*ft_new_line(char *map_line)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->next = NULL;
	new_map->map_line = ft_strdup(map_line);
	if (new_map->map_line == NULL)
		return (NULL);
	return (new_map);
}

void	ft_dup_map_line(char *map, t_stat *stat)
{
	t_map	*map_line;

	map_line = ft_new_line(map);
	if (map_line == NULL)
	{
		ft_free_map_list(stat);
		exit(0);
	}
	ft_lstadd_back(stat, map_line);
}

void	ft_parse_map(t_stat *stat)
{
	char	*map;

	map = get_next_line(stat->fd);
	while (map != NULL)
	{
		ft_dup_map_line(map, stat);
		free(map);
		map = get_next_line(stat->fd);
	}
	free(map);
}

int ft_is_collect_file(char *filename)
{
	int   	dot;
	size_t	len;
	size_t	t_len;

	dot = -1;
	len = ft_strlen(filename);
	t_len = len;
	while (len--)
	{
		if (filename[len] == '.')
		{
				dot = len;
		break ;
		}
	}
	if (dot == -1 || dot == t_len)
    return (0);
	else if (filename[dot + 1] == 'b' && filename[dot + 2] == 'e' && filename[dot + 3] == 'r' && dot + 4 == t_len)
		return (1);
	return (0);
}