/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:21:56 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/12 15:33:31 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(int fd, const char *format, ...);
int		write_char(int fd, va_list ap);
int		write_string(int fd, va_list ap);
int		write_address(int fd, va_list ap);
int		write_int(int fd, va_list ap);
int		write_uint(int fd, va_list ap);
int		write_hex(int fd, va_list ap, int is_lowercase);
int		wirte_percentage(int fd);
char	*ft_utoa(unsigned int n);
int		ft_print_hex(int fd, unsigned long long val, int is_lowercase);
int		ft_print_addr(int fd, unsigned long long addr_val);
char	*printf_itoa(int n);
size_t	printf_strlen(const char *s);

#endif
