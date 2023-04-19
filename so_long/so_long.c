#include "./so_long.h"

t_map	*ft_new_line(char *map_line)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->next = NULL;
	new_map->prev = NULL;
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
		ft_free_map(stat);
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

void	ft_init_stat(t_stat *stat)
{
	stat->fd = open("./map/map_false_symbol.ber", O_RDONLY);
	if (stat->fd <= 0)
		return ;
	stat->map = NULL;
	stat->escape_count = 0;
	stat->collect_count = 0;
	stat->start_count = 0;
	stat->win_width = 0;
	stat->win_height = 0;
	stat->move = 0;
	stat->player_x = 0;
	stat->player_y = 0;
	stat->ground = 0;
	stat->wall = 0;
	stat->collection = 0;
	stat->escape = 0;
	stat->player = 0;
}

void	so_long(t_stat *stat)
{
	int			is_collect_map;

	ft_parse_map(stat);
	is_collect_map = ft_check_map(stat);
	if (is_collect_map == -1)
	{
		ft_print_message("Error\n");
		ft_free_map(stat);
		exit(0);
	}
	ft_print_map(stat);
	printf("\n\nsuccessfully work!\n");
}

int main(void)
{
	t_stat		stat;

	ft_init_stat(&stat);
	so_long(&stat);
}