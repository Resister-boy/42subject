#include "./../so_long.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}