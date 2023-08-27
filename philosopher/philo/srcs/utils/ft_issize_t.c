/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issize_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:54:54 by francoma          #+#    #+#             */
/*   Updated: 2023/03/01 10:00:02 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

static unsigned int	are_digits(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static size_t	num_len(size_t num)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	nth_digit(size_t num, int nth)
{
	int	i;

	i = num_len(num) - 1;
	while (i > nth)
	{
		num /= 10;
		i--;
	}
	return (num % 10 + '0');
}

int	ft_issize_t(char *str)
{
	size_t	len;
	int		i;
	char	digit;

	while (ft_isspace(*str))
		str++;
	if (!are_digits(str))
		return (0);
	len = ft_strlen(str);
	if (len > num_len(SIZE_MAX))
		return (0);
	if (len < num_len(SIZE_MAX))
		return (1);
	i = 0;
	while (str[i])
	{
		digit = nth_digit(SIZE_MAX, i);
		if (str[i] > digit)
			return (0);
		if (str[i] < digit)
			return (1);
		i++;
	}
	return (1);
}
