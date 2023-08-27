/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:11:50 by francoma          #+#    #+#             */
/*   Updated: 2023/02/27 12:39:35 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;
	size_t	len;

	if (size == 0 || count == 0 || count > SIZE_MAX / size)
		return (NULL);
	res = malloc(size * count);
	if (!res)
		return (NULL);
	len = size * count;
	i = 0;
	while (i < len)
	{
		((char *) res)[i] = 0;
		i++;
	}
	return (res);
}
