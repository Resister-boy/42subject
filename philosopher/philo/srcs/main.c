/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:34:59 by francoma          #+#    #+#             */
/*   Updated: 2023/03/06 15:22:39 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

static int	valid_arg_format(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_issize_t(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_simulation	*simulation;

	if ((argc != 5 && argc != 6) || !valid_arg_format(argc, argv))
		exit_error(WRONG_ARGS_MSG);
	set_program_start_time();
	simulation = init_simulation(argc, argv);
	if (!simulation)
		exit_error(INIT_ERROR_MSG);
	wait_for_philosophers(simulation);
	end_simulation(simulation);
	return (EXIT_SUCCESS);
}
