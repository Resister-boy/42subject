/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:33:40 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/04 16:57:38 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t num)
{
	size_t			i;
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	i = 0;
	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	while (i < num && new_str1[i] == new_str2[i])
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)new_str1[i] - (unsigned char)new_str2[i]);
}
