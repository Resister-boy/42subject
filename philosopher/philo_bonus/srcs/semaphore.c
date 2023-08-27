/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:05:22 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 15:45:43 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define UINT_MAX_DECIMAL_LEN 10

void	write_protected_int(t_semaphore_int *sem_int, int val)
{
	if (sem_wait(sem_int->sem) == 0)
	{
		sem_int->val = val;
		sem_post(sem_int->sem);
	}
}

int	read_protected_int(t_semaphore_int *sem_int)
{
	int	val;

	val = 0;
	if (sem_wait(sem_int->sem) == 0)
	{
		val = sem_int->val;
		sem_post(sem_int->sem);
	}
	return (val);
}

int	init_semaphore(sem_t **sem, char *name, int value)
{
	*sem = sem_open(name, SEM_FLAGS, SEM_MODE, value);
	if (*sem == SEM_FAILED)
		return (ERROR);
	return (SUCCESS);
}

int	init_numbered_semaphore(sem_t **sem, char *prefix,
		unsigned int nb, int value)
{
	char	sem_name[128];

	if (ft_strlen(prefix) >= 128 - UINT_MAX_DECIMAL_LEN)
		return (ERROR);
	ft_prefixed_nb(sem_name, prefix, nb);
	sem_unlink(sem_name);
	*sem = sem_open(sem_name, SEM_FLAGS, SEM_MODE, value);
	if (*sem == SEM_FAILED)
		return (ERROR);
	return (SUCCESS);
}

void	close_numbered_semaphore(sem_t *sem, char *prefix,
		unsigned int nb)
{
	char	sem_name[128];

	sem_close(sem);
	if (ft_strlen(prefix) >= 128 - UINT_MAX_DECIMAL_LEN)
		return ;
	ft_prefixed_nb(sem_name, prefix, nb);
	sem_unlink(sem_name);
}
