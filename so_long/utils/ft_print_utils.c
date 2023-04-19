#include "./../so_long.h"

void  ft_print_message(char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
}