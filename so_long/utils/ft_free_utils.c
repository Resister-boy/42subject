#include "./../so_long.h"

void	ft_free_map(t_stat* stat)
{
	t_map	*map;
	t_map	*temp;

	if (stat->map == NULL)
		return ;
	map = stat->map;
	while (map != NULL)
	{
		temp = map->next;
		free(map->map_line);
		free(map);
		map = temp;
	}
	free(map);
}