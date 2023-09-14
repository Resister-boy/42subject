#include "philo_bonus.h"

int start_philo(t_table **table)
{
  int i;

  i = 0;
  (*table)->start_time = get_current_time();
  while (i < (*table)->args->philo_count)
  {
    (*table)->philos[i]->pid = fork();
    if ((*table)->philos[i]->pid == -1)
    {
      return (print_error("Process"));
    }
    if ((*table)->philos[i]->pid == 0)
    {
      if (handle_philo_life(*table, i))
        return (1);
    }
    else
      check_philo_life(*table);
  }
  return (0);
}

int main(int  argc, char **argv)
{
  t_table *table;

  if (!(argc == 5 || argc == 6))
    return (print_error("Arguments"));
  table = (t_table *)malloc(sizeof(t_table));
  if (table == NULL)
    return (print_error("Malloc"));
  memset(table, 0, sizeof(t_table));
  if (init(argc, argv, &table))
    return (print_error("Parse"));
  if (start_philo(table))
  {
    join_thread(&table);
    free_table(&table);
    return (print_error("Thread"));
  }
  return (0);
}