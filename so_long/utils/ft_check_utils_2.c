#include "./../so_long.h"

int ft_check_map(t_stat* stat)
{
  if (ft_is_map_square(stat->map) == 0)
    return (-1);
  if (ft_is_size_enough(stat->map) == 0)
    return (-1);
  if (ft_is_rounded_wall(stat->map) == 0)
    return (-1);
  if (ft_is_other_symbol(stat->map) == 0)
    return (-1);
  if (ft_is_symbol_ok(stat) == 0)
    return (-1);
  // if (ft_is_fe_ber(stat->map) == 0)
  //   return (-1);
//  if (ft_is_map_playable(stat->map) == 0)
//    return (-1);
  return (1); 
}