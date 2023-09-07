#include "philo.h"

void  join_thread(t_table **table)
{
  int i;

  i = 0;
  while (i < table->args->philo_count)
  {
    pthread_join(*(table->philos[i]->thread_id), NULL);
    i++;
  }
}

int check_is_dead(t_philo *philo)
{
  int   i;
  long  current;

  i = 0;
  while (i < philo->table->args->philo_count)
  {
    current = get_current_time();
    if ((current - philo->table->philos[i]->last_eat) >= philo->table->args->time_to_die)
    {
      print_state(philo->table->philos[i], "died");
      philo->table->is_done = 1;
    }
  }
}

void  check_is_done(t_philo *philo)
{
  while (!check_philo_status(philo->table))
  {
    if (!check_eat_count(philo))
    {
      philo->table->is_done = 1;
      break ;
    }
  }
}