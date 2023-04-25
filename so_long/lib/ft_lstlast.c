/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:17:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/25 14:17:14 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

t_map	*ft_lstlast(t_map *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}
