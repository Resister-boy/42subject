/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:09 by seonghle          #+#    #+#             */
/*   Updated: 2022/11/26 15:47:59 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_char_num(long long lln, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;

	lln = n;
	if (lln < 0)
	{
		write(fd, "-", 1);
		lln *= -1;
	}
	write_char_num(lln, fd);
}

static void	write_char_num(long long lln, int fd)
{
	char	c;

	c = lln % 10 + '0';
	if (lln < 10)
	{
		write(fd, &c, 1);
		return ;
	}
	write_char_num(lln / 10, fd);
	write(fd, &c, 1);
}
