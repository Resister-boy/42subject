/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:52:30 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/12 15:33:44 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_hex_index(unsigned long long val, int *hex_index_arr, int *i);

int	ft_print_hex(int fd, unsigned long long val, int is_lowercase)
{
	int		i;
	int		hex_index_arr[16];
	int		hex_str_len;
	char	*hex_result;
	char	*case_buffer;

	i = 0;
	if (val == 0)
		hex_index_arr[i++] = 0;
	else
		set_hex_index(val, hex_index_arr, &i);
	hex_result = (char *)malloc(sizeof(char) * (i + 1));
	if (!hex_result)
		return (-1);
	hex_result[i] = '\0';
	hex_str_len = i;
	if (is_lowercase)
		case_buffer = "0123456789abcdef";
	else
		case_buffer = "0123456789ABCDEF";
	while (--i >= 0)
		hex_result[i] = case_buffer[hex_index_arr[hex_str_len - i - 1]];
	hex_str_len = write(fd, hex_result, hex_str_len);
	free(hex_result);
	return (hex_str_len);
}

int	ft_print_addr(int fd, unsigned long long addr_val)
{
	int		i;
	int		hex_index_arr[16];
	int		hex_str_len;
	char	*hex_result;
	char	*buffer;

	i = 0;
	if (addr_val == 0)
		hex_index_arr[i++] = 0;
	else
		set_hex_index(addr_val, hex_index_arr, &i);
	hex_result = (char *)malloc(sizeof(char) * (i + 3));
	if (!hex_result)
		return (-1);
	hex_result[i + 2] = '\0';
	hex_result[0] = '0';
	hex_result[1] = 'x';
	hex_str_len = i + 2;
	buffer = "0123456789abcdef";
	while (--i >= 0)
		hex_result[i + 2] = buffer[hex_index_arr[hex_str_len - i - 3]];
	hex_str_len = write(fd, hex_result, hex_str_len);
	free(hex_result);
	return (hex_str_len);
}

static void	set_hex_index(unsigned long long val, int *hex_index_arr, int *i)
{
	while (val > 0)
	{
		hex_index_arr[(*i)++] = val % 16;
		val /= 16;
	}
}
