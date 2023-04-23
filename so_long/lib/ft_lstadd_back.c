#include "./../so_long.h"

void	ft_lstadd_back(t_stat *stat, t_map *new)
{
	t_map *last;

  if (stat->map_list == NULL)
    stat->map_list = new;
  else
  {
    last = ft_lstlast(stat->map_list);
    last->next = new;
  }
}