/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:21:03 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/12 15:19:31 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	search_format(int fd, const char *format, va_list ap, int *total_len);

int	ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (write(fd, format, 1) == -1)
			{
				total_len = -1;
				break ;
			}
			total_len++;
		}
		else
			if (search_format(fd, ++format, ap, &total_len) == -1)
				break ;
		format++;
	}
	va_end(ap);
	return (total_len);
}

static int	search_format(int fd, const char *format, va_list ap, int *total_len)
{
	int	result_len;

	if (*format == 'c')
		result_len = write_char(fd, ap);
	else if (*format == 's')
		result_len = write_string(fd, ap);
	else if (*format == 'p')
		result_len = write_address(fd, ap);
	else if (*format == 'd' || *format == 'i')
		result_len = write_int(fd, ap);
	else if (*format == 'u')
		result_len = write_uint(fd, ap);
	else if (*format == 'x')
		result_len = write_hex(fd, ap, 1);
	else if (*format == 'X')
		result_len = write_hex(fd, ap, 0);
	else if (*format == '%')
		result_len = wirte_percentage(fd);
	else
		result_len = -1;
	if (result_len == -1)
		*total_len = -1;
	else
		*total_len += result_len;
	return (*total_len);
}
