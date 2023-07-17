/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewolee <jaewolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:41:12 by jaewolee          #+#    #+#             */
/*   Updated: 2022/11/26 18:01:42 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp_hay;
	const char	*tmp_ndl;
	size_t		i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		tmp_hay = haystack;
		tmp_ndl = needle;
		i = len;
		while (*tmp_hay == *tmp_ndl && i--)
		{
			tmp_hay++;
			tmp_ndl++;
			if (!*tmp_ndl)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
