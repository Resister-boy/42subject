#include "./../so_long.h"

int ft_is_both_end_wall(char *str)
{
	size_t	end;

	end = ft_strlen(str) - 1;
	if (str[0] != '1' || str[end] != '1')
		return (0);
	return (1);
}

int ft_is_all_wall(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_count_flag(t_stat *stat, char symbol)
{
	if (symbol == '1')
		(stat->wall)++;
	else if (symbol == 'E')
		(stat->escape)++;
	else if (symbol == 'C')
		(stat->collection)++;
	else if (symbol == 'P')
		(stat->player)++;
	else if (symbol == '0')
		(stat->ground)++;
}