/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_set_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:59:16 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/26 17:38:50 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(int fd, va_list *ap)
{
	char	arg_ch;

	arg_ch = va_arg(*ap, int);
	return (write(fd, &arg_ch, 1));
}

int	write_string(int fd, va_list *ap)
{
	char	*arg_str;
	int		str_len;

	arg_str = va_arg(*ap, char *);
	if (!arg_str)
		return (write(fd, &"(null)", 6));
	str_len = printf_strlen(arg_str);
	if (str_len == 0)
		return (0);
	return (write(fd, arg_str, str_len));
}

int	write_address(int fd, va_list *ap)
{
	void	*arg_addr;

	arg_addr = va_arg(*ap, void *);
	return (ft_print_addr(fd, (unsigned long long)(arg_addr)));
}

int	write_int(int fd, va_list *ap)
{
	int		arg_int;
	char	*itoa_res;
	int		res_len;

	arg_int = va_arg(*ap, int);
	itoa_res = printf_itoa(arg_int);
	if (!itoa_res)
		return (-1);
	res_len = printf_strlen(itoa_res);
	if (write(fd, itoa_res, res_len) == -1)
	{
		free(itoa_res);
		return (-1);
	}
	free(itoa_res);
	return (res_len);
}

int	write_uint(int fd, va_list *ap)
{
	unsigned int	arg_uint;
	char			*utoa_res;
	int				res_len;

	arg_uint = va_arg(*ap, unsigned int);
	utoa_res = ft_utoa(arg_uint);
	if (!utoa_res)
		return (-1);
	res_len = printf_strlen(utoa_res);
	if (write(fd, utoa_res, res_len) == -1)
	{
		free(utoa_res);
		return (-1);
	}
	free(utoa_res);
	return (res_len);
}
