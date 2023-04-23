#include "./../so_long.h"

int	ft_check_symbol_utils(t_stat *stat, char *line, size_t row)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (ft_count_symbol(stat, line[i], i, row) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_symbol(t_stat *stat, char symbol, size_t col, size_t row)
{
	if (symbol == '1')
		(stat->wall)++;
	else if (symbol == '0')
		(stat->ground)++;
	else if (symbol == 'E')
		(stat->escape)++;
	else if (symbol == 'C')
		(stat->collection)++;
	else if (symbol == 'P')
	{
		(stat->player)++;
		stat->p_location.x = col;
		stat->p_location.y = row;
	}
	else
		return (0);
	return (1);
}

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