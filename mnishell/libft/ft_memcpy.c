/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:04:04 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/28 12:22:17 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*conv_dst;
	const unsigned char	*conv_src;

	if (!dst && !src)
		return (0);
	conv_dst = dst;
	conv_src = src;
	while (n--)
		*conv_dst++ = *conv_src++;
	return (dst);
}
