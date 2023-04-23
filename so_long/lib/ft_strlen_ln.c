#include "./../so_long.h"

size_t  ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len);
	}
	return (len);
}