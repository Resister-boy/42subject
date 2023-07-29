/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:06:31 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/04 16:58:05 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			new_dst[i] = new_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
			new_dst[len] = new_src[len];
	}
	return (dst);
}
