/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:57:45 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/04 16:57:59 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*new_dst;
	const unsigned char	*new_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	new_dst = (unsigned char *)dst;
	new_src = (const unsigned char *)src;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (new_dst);
}
