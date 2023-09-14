#include "philo_bonus.h"

void  free_table(t_table **table)
{
  free_philos(*table);
  free_args(*table);
  sem_close((*table)->sem_forks);
  sem_close((*table)->sem_print);
  sem_close((*table)->sem_init);
  sem_close((*table)->sem_death);
}

void  free_philos(t_table *table)
{
  int i;

  i = 0;
  while (i < table->args->philo_count)
  {
    free(table->philos[i]);
    i++;
  }
  free(table->philos);
}

void  free_args(t_table *table)
{
  free(table->args)
}