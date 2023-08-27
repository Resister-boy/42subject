/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:25:16 by francoma          #+#    #+#             */
/*   Updated: 2023/03/11 19:19:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "utils.h"
# include "messages.h"
# include "time.h"

typedef struct s_forks
{
	pthread_mutex_t	mutex;
	int				used_by;
}	t_fork;

typedef struct s_philosopher
{
	pthread_t			t;
	int					id;
	t_mutex_int			state;
	size_t				eat_count;
	size_t				last_meal_ms;
	size_t				last_nap_ms;
	struct s_simulation	*simulation;
}	t_philosopher;

typedef struct s_simulation
{
	size_t			philo_qty;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat_count;
	t_mutex_int		over;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philosopher	*philosophers;
}	t_simulation;

# define PHILOSOPHING 0
# define DONE 1
# define CONTINUE 0
# define STOP 1

# define NOBODY -1
# define MAIN_SLEEP 1000
# define PHILO_SLEEP 100
# define PHILO_ORDERING_SLEEP 2500
# define SUCCESS 0

t_simulation	*init_simulation(int argc, char *argv[]);
void			end_simulation(t_simulation *simulation);

int				die(t_philosopher *philo);
int				is_starved(t_philosopher *philo);
int				take_forks(t_philosopher *philo);
void			put_down_forks(t_philosopher *philo);
void			*philosophing(void *arg);
void			wait_for_philosophers(t_simulation *simulation);

int				print_msg(t_philosopher *philo, char *format);
void			print_last_msg(t_philosopher *philo, char *format);

#endif