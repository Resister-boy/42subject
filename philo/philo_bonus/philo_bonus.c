#include "philo_bonus.h"

int handle_philo_life(t_table *table, int idx)
{
  if (pthread_create(table->philos[i]->thread_id, NULL), \
  philo_life, table->philos[idx])
    return (1);
  philo_life(table->philos[idx]);
  return (0);
}

int philo_life(t_philo *philo)
{
  if (philo->philo_idx % 2)
    usleep(100);
  while (check_philo_status(phlio->table))
  {
    if (get_fork(philo))
      break ;
    if (eating(philo))
      break ; 
    if (sleeping(philo))
      break ;
    if (thinking(philo))
      break ;
  }
}

void check_philo_life(t_table *table)
{
  pid_t child;
  int   i;

  i = 0;
  while (i < table->args->philo_count)
  {
    waitpid(-1, &child, 0);
    if (!child)
    {
      i = 0;
      while (i < table->args->philo_count)
      {
        kill(table->philos[i], SIGKILL);
        i++;
      }
    }
    i++;
  }
}
