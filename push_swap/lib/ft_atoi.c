#include "./../push_swap.h"

int	ft_atoi(const char *str)
{
	long long int	sign;
	long long int	value;

	sign = 1;
	value = 0;
	while (*str != '\0' && *str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		value *= 10;
		value += *str - 48;
		str++;
	}
	return (value * sign);
}