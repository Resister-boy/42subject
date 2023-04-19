#include "./../so_long.h"

t_map	*ft_lstlast(t_map *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}