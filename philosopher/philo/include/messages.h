/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:45 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 14:24:26 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define WRONG_ARGS_MSG "ARGS:\n\
	number_of_philosophers (and of forks)\n\
	time_to_die (ms) max time between eat start\n\
	time_to_eat (ms)\n\
	time_to_sleep (ms)\n\
	[number_of_times_each_philosopher_must_eat]\n\
		if every philosopher has eaten that many times, end\n\
		otherwise, end only when a philosopher dies\n"
# define INIT_ERROR_MSG "Error while initializing simulation\n"

# define MSG_FORK "%lu %i has taken a fork\n"
# define MSG_EAT "%lu %i is eating\n"
# define MSG_SLEEP "%lu %i is sleeping\n"
# define MSG_THINK "%lu %i is thinking\n"
// # define MSG_DIE "\033[0;31m%lu %i died\033[0m\n"
# define MSG_DIE "%lu %i died\n"

#endif
