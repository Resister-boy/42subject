/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_set_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:59:29 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/26 17:39:04 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hex(int fd, va_list *ap, int is_lowercase)
{
	unsigned int	arg_uint;

	arg_uint = va_arg(*ap, unsigned int);
	return (ft_print_hex(fd, (unsigned long long)arg_uint, is_lowercase));
}

int	wirte_percentage(int fd)
{
	return (write(fd, &"%", 1));
}
