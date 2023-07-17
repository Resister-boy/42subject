/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:54:08 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/26 14:48:02 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*conv_s1;
	const unsigned char	*conv_s2;

	conv_s1 = s1;
	conv_s2 = s2;
	while (n--)
	{
		if (*conv_s1 != *conv_s2)
			return ((int)(*conv_s1 - *conv_s2));
		conv_s1++;
		conv_s2++;
	}
	return (0);
}
