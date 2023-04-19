#include "./../so_long.h"

void	ft_print_map(t_stat *stat)
{
	t_map	*map;

	map = stat->map;
	while (map != NULL)
	{
		printf("%s", map->map_line);
		map = map->next;
	}
}