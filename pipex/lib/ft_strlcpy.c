/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:47:02 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 11:47:43 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (ft_strlen(dst));
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
