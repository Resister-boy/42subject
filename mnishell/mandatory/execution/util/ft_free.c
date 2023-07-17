/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 04:25:58 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/27 22:30:55 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free(void **target)
{
	if (*target)
		free(*target);
	*target = NULL;
	return (0);
}

int	ft_free_2dim(void ***target)
{
	if (*target)
		free(*target);
	*target = NULL;
	return (0);
}
