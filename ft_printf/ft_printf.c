/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:18:29 by jaehulee          #+#    #+#             */
/*   Updated: 2023/01/11 15:00:06 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char chr, int *point)
{
	int	value;

	value = write(1, &chr, 1);
	if (value == -1)
	{
		(*point) = -1;
		return (-1);
	}
	return (1);
}

int	ft_check_is_spec(char *specs, char flag)
{
	while (*specs)
	{
		if (*specs == flag)
			return (1);
		specs++;
	}
	return (0);
}

int	ft_check_spec(va_list ap, char flag, int *point)
{
	char	*specs;

	specs = "csdiuxXp%";
	if (flag == '\0' || (!ft_check_is_spec(specs, flag)))
		return (-1);
	if (flag == specs[0])
		ft_char(ap, point);
	else if (flag == specs[1])
		ft_string(ap, point);
	else if (flag == specs[2] || flag == specs[3])
		ft_signed_decimal(ap, flag, point);
	else if (flag == specs[4])
		ft_unsigned_decimal(ap, flag, point);
	else if (flag == specs[5] || flag == specs[6])
		ft_heximal(ap, flag, point);
	else if (flag == specs[7])
		ft_pointer(ap, point);
	else if (flag == specs[8])
	{
		if (ft_putchar('%', point) == -1)
			return (*point);
		(*point)++;
	}
	return (*point);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		point;
	char	flag;

	point = 0;
	va_start(ap, format);
	while (*format)
	{
		if ((*format) == '%')
		{
			flag = *(format + 1);
			if (ft_check_spec(ap, flag, &point) == -1)
				return (point);
			format++;
		}
		else
		{
			if (ft_putchar(*format, &point) == -1)
				return (point);
			point++;
		}
		format++;
	}
	va_end(ap);
	return (point);
}
