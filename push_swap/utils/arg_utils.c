#include "./../push_swap.h"

int	ft_check_only_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && 57 >= str[i])
			i++;
		else
			return (-1);
	}
	return (1);
}

int  ft_check_double(int current, size_t current_idx, char **args)
{
  size_t	i;
	size_t	j;

  i = 0;
  while (args[i] != NULL)
  {
    if (i != current_idx && current == ft_atoi(args[i]))
      return (-1);
    i++;
  }
  return (1);
}

char  **ft_check_args(int argc, char **argv)
{
  size_t         i;
  long long int  num;
  char           **args;

  i = 0;
  if (argc == 2)
    args = ft_split(argv[1], ' ');
  else
  {
    i = 1;
    args = argv;
  }
  while (args[i])
  {
    num = ft_atoi(args[i]);
    if (!ft_check_only_num(args[i]))
      ft_error("Error\n");
    if (!ft_check_double(num, i, args))
      ft_error("Error\n");
		if (num < -2147483648 || num > 2147483647)
			ft_error("Error\n");
		i++;
  }
  if (argc == 2)
    ft_free(args);
  return (args);
}