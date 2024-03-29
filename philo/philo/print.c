/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:52:28 by jaehulee          #+#    #+#             */
/*   Updated: 2023/09/14 18:14:34 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg)
{
	printf("%s error", msg);
	return (1);
}

void	print_state(int philo, char *action)
{
	printf("%d %s", philo, action);
}
