/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:52:15 by seonghle          #+#    #+#             */
/*   Updated: 2022/11/26 16:23:37 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	calc_len(char const *s1, char const *s2, \
		size_t *s1_len, size_t *s2_len);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	alloc_len;
	char	*result;
	int		flag;

	if (!s1 || !s2)
		return (0);
	calc_len(s1, s2, &s1_len, &s2_len);
	alloc_len = s1_len + s2_len;
	result = (char *)malloc(sizeof(char) * (alloc_len + 1));
	if (!result)
		return (0);
	ft_memset(result, 0, alloc_len + 1);
	if (alloc_len == 0)
		return (result);
	flag = 0;
	if (s1_len != 0)
	{
		ft_strlcpy(result, s1, s1_len + 1);
		flag = 1;
	}
	if (s2_len != 0)
		ft_strlcat(result, s2, s1_len * flag + s2_len + 1);
	return (result);
}

static void	calc_len(char const *s1, char const *s2, \
		size_t *s1_len, size_t *s2_len)
{
	if (!s1)
		*s1_len = 0;
	else
		*s1_len = ft_strlen(s1);
	if (!s2)
		*s2_len = 0;
	else
		*s2_len = ft_strlen(s2);
}
