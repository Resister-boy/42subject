/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:04:16 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/04 16:33:05 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	change_abs(int c)
{
	if (c < 0)
		return (c * -1);
	return ((char)c);
}

char	*ft_itoa(int n)
{
	int		str_len;
	int		sign;
	char	*result;

	sign = 1;
	if (n < 0)
		sign *= -1;
	str_len = count_length(n);
	result = (char *)ft_calloc(sizeof(char), (str_len + 1));
	if (!result)
		return (NULL);
	result[str_len--] = 0;
	while (str_len >= 0)
	{
		result[str_len] = change_abs(n % 10) + '0';
		n /= 10;
		str_len--;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
