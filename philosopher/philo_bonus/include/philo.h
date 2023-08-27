/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:25:16 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 16:02:00 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include "utils.h"
# include "messages.h"
# include "time.h"

typedef struct s_semaphore_int
{
	sem_t	*sem;
	int		val;
}	t_semaphore_int;

typedef struct s_philosopher
{
	ssize_t				id;
	size_t				eat_count;
	t_semaphore_int		has_forks;
	int					done;
	size_t				last_meal_ms;
	size_t				last_nap_ms;
	struct s_simulation	*simulation;
	pid_t				pid;
}	t_philosopher;

typedef struct s_simulation
{
	size_t			philo_qty;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat_count;
	sem_t			*start;
	sem_t			*forks;
	sem_t			*print;
	t_philosopher	*philosophers;
}	t_simulation;

# define DONE 0
# define DEAD 1
# define NO_CHILD_PROCESS_LEFT -1
# define ANY_CHILD_PROCESS -1

# define PHILO_SLEEP 300

# define SEM_FORKS "forks"
# define SEM_START "start"
# define SEM_PRINT "print"
# define SEM_PHILO "philo"
# define SEM_FLAGS O_CREAT
# define SEM_MODE 0600

# define ERROR -1
# define SUCCESS 0

t_simulation	*init_simulation(int argc, char *argv[], int *is_main_process);

int				is_starved(t_philosopher *philo);
void			die(t_philosopher *philo);
int				is_done_sleeping(t_philosopher *philo);
int				is_done_eating(t_philosopher *philo);
int				has_eaten_enough_times(t_philosopher *philo);

void			*take_forks(void *arg);
void			put_down_forks(t_philosopher *philo);
void			*philosophing(void *arg);
void			wait_philosophers(t_simulation *simulation);

void			write_protected_int(t_semaphore_int *sem_int, int val);
int				read_protected_int(t_semaphore_int *sem_int);
int				init_semaphore(sem_t **sem, char *name, int value);
int				init_numbered_semaphore(sem_t **sem, char *name,
					unsigned int nb, int value);
void			close_numbered_semaphore(sem_t *sem, char *prefix,
					unsigned int nb);

#endif