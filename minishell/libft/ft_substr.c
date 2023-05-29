/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:30:17 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/26 17:40:14 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	alloc_len;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len > start)
		alloc_len = s_len - start;
	else
		alloc_len = 0;
	if (alloc_len > len)
		alloc_len = len;
	result = malloc(sizeof(char) * (alloc_len + 1));
	if (!result)
		return (0);
	result[alloc_len] = '\0';
	i = 0;
	while (i < alloc_len)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}
