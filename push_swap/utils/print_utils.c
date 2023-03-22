#include "./../push_swap.h"

void  ft_print_command(char *command)
{
  size_t  i;

  i = 0;
  while (command[i] != '\0')
  {
    write(1, &command[i], 1);
    i++;
  }
}

void  ft_error(char *error)
{
  size_t  i;

  i = 0;
  while (error[i] != '\0')
  {
    write(1, &error[i], 1);
    i++;
  }
  exit(0);
}
