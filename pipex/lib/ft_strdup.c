/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:05:14 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 03:05:52 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
