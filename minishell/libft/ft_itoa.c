/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:52:28 by seonghle          #+#    #+#             */
/*   Updated: 2022/11/26 14:24:13 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len(long long lln);
static void	set_result(char **result, long long lln, int i, int flag);

char	*ft_itoa(int n)
{
	char		*result;
	long long	lln;
	int			alloc_len;
	int			flag;
	int			i;

	lln = n;
	flag = 0;
	if (lln < 0)
	{
		flag = 1;
		lln *= -1;
	}
	alloc_len = calc_len(lln) + flag;
	result = (char *)malloc(sizeof(char) * (alloc_len + 1));
	if (!result)
		return (0);
	result[alloc_len] = 0;
	if (flag)
		result[0] = '-';
	i = alloc_len - 1;
	set_result(&result, lln, i, flag);
	return (result);
}

static int	calc_len(long long lln)
{
	if (lln < 10)
		return (1);
	return (1 + calc_len(lln / 10));
}

static void	set_result(char **result, long long lln, int i, int flag)
{
	if (i < flag)
		return ;
	set_result(result, lln / 10, i - 1, flag);
	(*result)[i] = lln % 10 + '0';
}
