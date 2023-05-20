/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:47:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/15 14:51:46 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

size_t	ft_strslen(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**ft_strsdup(char **strs)
{
	size_t	i;
	size_t	len;
	char	**c_strs;

	i = 0;
	len = ft_strslen(strs);
	c_strs = (char **)malloc(sizeof(char *) * (len + 1));
	c_strs[len] = NULL;
	while (i < len)
	{
		c_strs[i] = ft_strdup(strs[i]);
		i++;
	}
	return (c_strs);
}
