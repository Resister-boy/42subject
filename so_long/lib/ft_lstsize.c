/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:17:21 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:17:21 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

size_t	ft_lstsize(t_map *map)
{
	size_t				len;

	len = 0;
	while (map != NULL)
	{
		map = map->next;
		len++;
	}
	return (len);
}
