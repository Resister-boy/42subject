#include "philo_bonus.h"

int get_fork(t_philo *philo)
{
  if (philo->table->args == 1)
  {
    sem_wait(philo->table->sem_forks);
		print_state(philo, "has taken a fork");
    sem_wait(philo->table->sem_forks);
    return (1);
  }
  sem_wait(philo->table->sem_forks);
  print_state(philo, "has taken a fork");
	sem_wait(philo->fork);
	print_state(philo, "has taken a fork");
  return (0);
}

void  monitering(t_table *table)
{
  int       i;
  long long current;

  while (table->is_done != 1)
  {
    if (!check_eat_count(table))
      table->is_done = 1;
    i = 0;
    while (i < table->args->philo_count)
    {
      if (check_is_dead(table->philos[i]))
        break ;
      i++;
    }
  }
}
