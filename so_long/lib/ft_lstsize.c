#include "./../so_long.h"

size_t	ft_lstsize(t_map *map)
{
	size_t				len;

	len = 0;
	while (map != NULL)
	{
		map = map->next;
		len++;
	}
	return (len);
}