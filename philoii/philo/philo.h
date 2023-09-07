/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:14:53 by jaehulee          #+#    #+#             */
/*   Updated: 2023/08/29 22:34:19 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_fork
{
	unsigned int	idx;
	pthread_mutex_t	fork;
	int				status;
}	t_fork;

typedef struct s_args
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_args;

typedef struct s_philo
{
	unsigned int	philo_idx;
	unsigned int	last_ate;
	unsigned int	last_sleep;
	unsigned int	is_dead;
	unsigned int	eat_count;
	int				left_fork;
	int				right_fork;
	pthread_t		thread_id;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_args			*args;
	t_philo			**philos;
	t_fork			**forks;
	pthread_mutex_t	mutex_init;
	pthread_mutex_t	mutex_monitor;
	pthread_mutex_t	mutex_eat_count;
	pthread_mutex_t	mutex_last_eat;
	int				is_done;
}	t_table;

int	atou(char *argv);
int	init(int argc, char **argv, t_table **table);

int	print_error(char *msg);
int	print_state(int philo, char *action, int type);

int	eating(t_table *table);
int	thinking(t_table *table);
int	sleeping(t_table *table);
int	died(t_table *table);

#endif