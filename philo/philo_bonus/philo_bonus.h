#ifndef PHILO_BONUS_H
#include PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <semaphore.h>

typedef struct  s_args
{
  int philo_count;
  int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
} t_args;

typedef struct  s_philo
{
  t_args  *args;
  unsigned int  philo_idx;
  unsigned int  last_eat;
 	unsigned int	last_sleep;
	unsigned int	is_dead;
	unsigned int	eat_count;
  pid_t         *pid;
	pthread_t		  thread_id;
  struct  s_table *table; 
} t_philo;

typedef struct  s_table
{
  t_args        *args;
  t_philo       *philos;
  sem_t         *sem_forks;
  sem_t         *sem_print;
  sem_t         *sem_init;
  sem_t         *sem_death;
  long long int start_time;
} t_table;

#endif