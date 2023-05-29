/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:58:02 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/28 12:27:27 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*con_s1;
	const unsigned char	*con_s2;

	if (n == 0)
		return (0);
	con_s1 = (const unsigned char *)s1;
	con_s2 = (const unsigned char *)s2;
	while (*con_s1 && *con_s2 && --n)
	{
		if (*con_s1 != *con_s2)
			return (*con_s1 - *con_s2);
		con_s1++;
		con_s2++;
	}
	return (*con_s1 - *con_s2);
}
