/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:32:38 by seonghle          #+#    #+#             */
/*   Updated: 2022/11/26 18:01:08 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	conv_c;

	conv_c = c;
	while (*s)
	{
		if (*s == conv_c)
			return ((char *)s);
		s++;
	}
	if (*s == conv_c)
		return ((char *)s);
	return (0);
}
