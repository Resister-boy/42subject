/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:47:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:09:35 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_strsdup(char **strs)
{
	int		i;
	int		len;
	char	**c_strs;

	if (!strs)
		return (NULL);
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
