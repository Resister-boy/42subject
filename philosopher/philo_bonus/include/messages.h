/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:34:45 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 18:04:00 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define WRONG_ARGS "ARGS:\n\
	number_of_philosophers (and of forks)\n\
	time_to_die (ms) max time between eat start\n\
	time_to_eat (ms)\n\
	time_to_sleep (ms)\n\
	[number_of_times_each_philosopher_must_eat]\n\
		if every philosopher has eaten that many times, end\n\
		otherwise, end only when a philosopher dies\n"

# define FAILED_TO_INIT_SIMULATION "Failed to initialize simulation\n"

# define MSG_FORK "%lu %li has taken a fork\n"
# define MSG_EAT "%lu %li is eating\n"
# define MSG_SLEEP "%lu %li is sleeping\n"
# define MSG_THINK "%lu %li is thinking\n"
# define MSG_DIE "\033[0;31m%lu %li died\033[0m\n"

#endif
