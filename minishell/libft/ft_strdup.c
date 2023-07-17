/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewolee <jaewolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:17:37 by jaewolee          #+#    #+#             */
/*   Updated: 2022/11/26 15:57:24 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!result)
		return (0);
	result[s1_len] = 0;
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
