/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:51:01 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/28 11:44:11 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_res(const char *s1, char *result, size_t i, size_t s1_len);
static int	ft_search(char const s1, char const *set);
static char	*alloc_result(size_t i, size_t s1_len, int flag);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	s1_len;
	int		flag;

	if (!s1 || !set)
		return (0);
	i = 0;
	flag = 1;
	while (s1[i] && ft_search(s1[i], set))
		i++;
	s1_len = ft_strlen(s1);
	if (s1_len)
	{
		--s1_len;
		while (s1_len > 0 && ft_search(s1[s1_len], set))
			s1_len--;
	}
	else
		flag = 0;
	result = alloc_result(i, s1_len, flag);
	if (!result)
		return (0);
	ft_set_res(s1, result, i, s1_len);
	return (result);
}

static int	ft_search(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i++])
			return (1);
	}
	return (0);
}

static void	ft_set_res(const char *s1, char *result, size_t i, size_t s1_len)
{
	size_t	j;

	j = 0;
	while (i <= s1_len)
		result[j++] = s1[i++];
}

static char	*alloc_result(size_t i, size_t s1_len, int flag)
{
	char	*result;

	if (s1_len < i)
	{
		result = (malloc(sizeof(char)));
		if (!result)
			return (0);
		result[0] = 0;
		return (result);
	}
	else
	{
		result = (malloc(sizeof(char) * (s1_len - i + flag + 1)));
		if (!result)
			return (0);
		result[s1_len - i + flag] = 0;
		return (result);
	}
}
