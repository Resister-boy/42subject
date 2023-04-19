#include "./../so_long.h"

size_t  ft_total_len(char **strs)
{
  size_t  len;

  len = 0;
  while (strs[len])
    len++;
  return (len);
}