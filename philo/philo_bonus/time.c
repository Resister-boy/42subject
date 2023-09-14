#include "philo_bonus.h"

long  get_current_time(void)
{
  struct  timeval time;
  long            current;

  gettimeofday(&time, NULL);
  current = ((long)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
  return (current);
}