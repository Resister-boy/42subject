/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:07:40 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 21:45:16 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_fork
{
	unsigned int	idx;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_args
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_args;

typedef struct s_table
{
	t_args			*args;
	struct s_philo	**philos;
	t_fork			**forks;
	pthread_mutex_t	mutex_init;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	mutex_eat_count;
	pthread_mutex_t	mutex_last_eat;
	int				is_done;
}	t_table;

typedef struct s_philo
{
	unsigned int	philo_idx;
	unsigned int	last_eat;
	unsigned int	last_sleep;
	unsigned int	is_dead;
	unsigned int	eat_count;
	int				left_fork;
	int				right_fork;
	pthread_t		thread_id;
	t_table			*table;
}	t_philo;

void	*philo_life(void *data);
int		atou(char *argv);
int		init(int argc, char **argv, t_table **table);
void	join_thread(t_table **table);
int		check_is_dead(t_philo *philo);
void	free_table(t_table **table);
int		print_error(char *msg);
void	print_state(int philo, char *action);
long	get_current_time(void);
int		check_philo_status(t_philo *philo);
int		get_fork(t_philo *philo);
int		check_eat_count(t_table *table);
void	monitering(t_table *table);

#endif