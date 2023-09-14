#include "philo_bonus.h"

int	atou(char *argv)
{
	size_t	i;
	int		value;

	i = 0;
	value = 0;
	while (argv[i])
	{
		if (argv[i] >= 48 && argv[i] <= 57)
		{
			value *= 10;
			value += argv[i] - 48;
		}
		else
			return (-1);
		i++;
	}
	return (value);
}