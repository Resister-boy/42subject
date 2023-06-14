/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:40:42 by ysoroko           #+#    #+#             */
/*   Updated: 2021/07/09 14:41:19 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	else
	{
		return (c);
	}
}
