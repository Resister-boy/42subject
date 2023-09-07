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
  if (philo->table->args->philo_count == 1)
  {
    pthread_mutex_lock(&(philo->table->fork[philo->left]));
		print_state(philo, "has taken a fork");
		pthread_mutex_unlock(&(philo->table->fork[philo->left]));
		return (1);
  }
  pthread_mutex_lock(&(philo->table->forks[philo->left_fork]));
  print_state(philo, "has taken a fork");
  pthread_mutex_lock(&(philo->table->forks[philo->right_fork]));
  print_state(philo, "has taken a fork");
  return (0);
}

int check_eat_count(t_philo *philo)
{
  int i;

  i = 0;
  if (philo->table->args->eat_count == 0)
    return (1);
  while (i < philo->table->args->philo_count)
  {
    if (philo->table->philos[i]->eat_count != philo->table->args->eat_count)
      return (1);
    i+;
  }
  return (0);
}