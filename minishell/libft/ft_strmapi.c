/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:00 by chbaek            #+#    #+#             */
/*   Updated: 2022/11/26 17:09:40 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	s_len;
	unsigned int	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (0);
	result[s_len] = 0;
	while (i < s_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
