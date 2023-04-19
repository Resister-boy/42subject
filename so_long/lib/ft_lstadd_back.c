#include "./../so_long.h"

void	ft_lstadd_back(t_stat *stat, t_map *new)
{
	t_map *last;

  if (stat->map == NULL)
    stat->map = new;
  else
  {
    last = ft_lstlast(stat->map);
    last->next = new;
    new->prev = last;
  }
}