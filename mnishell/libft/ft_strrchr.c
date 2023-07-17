/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:56:23 by chbaek            #+#    #+#             */
/*   Updated: 2022/11/26 18:01:18 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char		conv_c;
	const char	*result;

	conv_c = c;
	result = 0;
	while (*s)
	{
		if (*s == conv_c)
			result = s;
		s++;
	}
	if (*s == conv_c)
		return ((char *)s);
	return ((char *)result);
}
