/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:59:51 by chbaek            #+#    #+#             */
/*   Updated: 2022/11/26 15:31:51 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	conv_c;
	unsigned char	*conv_b;
	size_t			i;

	conv_c = c;
	conv_b = b;
	i = 0;
	while (i < len)
	{
		conv_b[i] = conv_c;
		i++;
	}
	return (b);
}
