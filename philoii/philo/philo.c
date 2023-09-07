/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:14:50 by jaehulee          #+#    #+#             */
/*   Updated: 2023/08/30 13:41:05 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->table->mutex_init));
	printf("philo_idx %d\n", philo->philo_idx);
	printf("philo_thread_id %d\n", (int)philo->thread_id);
	if (philo->philo_idx % 2 == 1)
		usleep(50);
	eat
	return (NULL);
}

int	start_philo(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table->mutex_init));
	while (i < table->args->philo_count)
	{
		if (pthread_create(&(table->philos[i]->thread_id), NULL, \
		run_philo, &(table->philos[i]->philo_idx)))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&(table->mutex_init));
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!(argc == 5 || argc == 6))
		return (print_error("Arguments"));
	table = (t_table *)malloc(sizeof(t_table));
	if (table == NULL)
		return (1);
	memset(table, 0, sizeof(t_table));
	if (init(argc, argv, &table))
		return (print_error("Parse"));
	start_philo(table);
	return (0);
}
