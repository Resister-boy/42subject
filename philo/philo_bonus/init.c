#include "philo_bonus.h"

static int	init_args(int argc, char **argv, t_table **table)
{
	(*table)->args->philo_count = atou(argv[1]);
	(*table)->args->time_to_die = atou(argv[2]);
	(*table)->args->time_to_eat = atou(argv[3]);
	(*table)->args->time_to_sleep = atou(argv[4]);
	if ((*table)->args->philo_count == -1 \
	|| (*table)->args->time_to_die == -1 \
	|| (*table)->args->time_to_eat == -1 \
	|| (*table)->args->time_to_sleep == -1)
		return (1);
	if (argc == 6)
	{
		(*table)->args->must_eat_count = atou(argv[5]);
		if ((*table)->args->must_eat_count == -1)
			return (1);
	}
	return (0);
}

static int  init_philos(t_table **table)
{
  int i;

  i = 0;
  (*table)->philos = (t_philo **)malloc(sizeof(t_philo *) * \
	((*table)->args->philo_count));
	if ((*table)->philos == NULL)
		return (1);
	while (i < ((*table)->args->philo_count))
	{
		(*table)->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		(*table)->philos[i]->philo_idx = i;
		(*table)->philos[i]->eat_count = 0;
		(*table)->philos[i]->is_dead = 0;
		(*table)->philos[i]->last_eat = 0;
		(*table)->philos[i]->last_sleep = 0;
		i++;
	}
  return (0);
}

static int  init_sem(t_table **table)
{
  sem_unlink('sem_forks');
  (*table)->sem_forks = sem_open("sem_fork", O_CREAT, 0644, philo->philo_num);
	if ((*table)->sem_forks == SEM_FAILED)
		return (1);
  sem_unlink('sem_print');
	(*table)->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	if ((*table)->sem_print == SEM_FAILED)
		return (1);
  sem_unlink('sem_init');
	(*table)->sem_init = sem_open("sem_init", O_CREAT, 0644, 1);
	if ((*table)->sem_init == SEM_FAILED)
		return (1);
  sem_unlink('sem_death');
	(*table)->sem_death = sem_open("sem_death", O_CREAT, 0644, 1);
	if ((*table)->sem_death == SEM_FAILED)
		return (1);
	return (0);
}

int init(int argc, char **argv, t_table **table)
{
  (*table)->args = (t_args *)malloc(sizeof(t_args));
	if ((*table)->args == NULL)
		return (1);
	if (init_args(argc, argv, table))
		return (1);
	if (init_sem(table))
		return (1);
	if (init_philos(table))
		return (1);
	return (0);
}