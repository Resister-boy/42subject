/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:39 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/12 15:30:49 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_len(long long lln);
static void	set_result(char **result, long long lln, int i, int flag);

char	*printf_itoa(int n)
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
