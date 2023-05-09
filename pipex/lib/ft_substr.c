/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:40:48 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 02:42:09 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*result;

	i = 0;
	j = start;
	s_len = ft_strlen(str);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		result[i++] = str[j++];
	result[i] = 0;
	return (result);
}
