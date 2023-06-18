/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:47:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/18 03:20:25 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_strsdup(char **strs)
{
	size_t	i;
	size_t	len;
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
