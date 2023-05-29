/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:01:53 by chbaek            #+#    #+#             */
/*   Updated: 2022/11/26 14:38:13 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		conv_c;
	const unsigned char	*conv_s;

	conv_c = c;
	conv_s = s;
	while (n--)
	{
		if (*conv_s == conv_c)
			return ((void *)conv_s);
		conv_s++;
	}
	return (0);
}
