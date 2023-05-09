/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:36:38 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 11:36:48 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*result;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
