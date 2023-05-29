/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:35 by seonghle          #+#    #+#             */
/*   Updated: 2022/11/28 10:37:01 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_val(unsigned char *dst, const unsigned char *src, \
		size_t len, int direction);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (dst > src)
		copy_val(dst + len - 1, src + len - 1, len, -1);
	else
		copy_val(dst, src, len, 1);
	return (dst);
}

static void	copy_val(unsigned char *dst, const unsigned char *src, \
		size_t len, int direction)
{
	while (len--)
	{
		*dst = *src;
		dst += direction;
		src += direction;
	}
}
