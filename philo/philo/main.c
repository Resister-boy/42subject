/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:56:10 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 21:11:11 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_philo(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table->mutex_init));
	while (i < table->args->philo_count)
	{
		pthread_mutex_lock(&(table->mutex_last_eat));
		table->philos[i]->last_eat = get_current_time();
		pthread_mutex_unlock(&(table->mutex_last_eat));
		table->philos[i]->last_sleep = get_current_time();
		if (pthread_create(&(table->philos[i]->thread_id), NULL, \
		philo_life, &(table->philos[i])))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&(table->mutex_init));
	monitering(table);
	i = 0;
	while (i < table->args->philo_count)
		pthread_join(table->philos[i]->thread_id, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
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
