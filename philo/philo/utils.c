#include "philo.h"

int check_philo_status(t_table *table)
{
  pthread_mutex_lock(table->mutex_monitor);
  if (table->is_done)
  {
    pthread_mutex_unlock(table->mutex_monitor);
		return (1)
  }
  else
  {
    pthread_mutex_unlock(table->mutex_monitor);
		return (0);
  }
}

int get_fork(t_philo *philo)
{
  pthread_mutex_lock(&(philo->table->fork[philo->left_fork]));
  print_state(philo, "has taken a fork");
  if (philo->table->args->philo_count == 1)
  {
		pthread_mutex_unlock(&(philo->table->fork[philo->left_fork]));
		return (1);
  }
  pthread_mutex_lock(&(philo->table->forks[philo->left_fork]));
  print_state(philo, "has taken a fork");
  pthread_mutex_lock(&(philo->table->forks[philo->right_fork]));
  print_state(philo, "has taken a fork");
  return (0);
}

int check_eat_count(t_table *table)
{
  int i;

  i = 0;
  if (table->args->must_eat_count == 0)
    return (1);
  while (i < table->args->philo_count)
  {
    if (table->philos[i]->eat_count != table->args->must_eat_count)
      return (1);
    i++;
  }
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