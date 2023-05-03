/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:53 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/03 17:59:10 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_finish_program(t_stat *stat)
{
	ft_free_map_arr(stat, &(stat->map_arr));
	exit(0);
}

void	ft_print_move(t_stat *stat)
{
	char	*base;

	base = "0123456789";
	ft_print_decimal(stat->move, base);
	write(1, "\n", 1);
}

void	ft_print_decimal(int n, char *base)
{
	long long	num;

	num = n;
	if (num / 10 > 0)
		ft_print_decimal(num / 10, base);
	write(1, &base[num % 10], 1);
}
