/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:56:29 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 19:11:06 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	*expand_env(char **buf)
{
	size_t	i;
	size_t	len;
	char	**c_buf;
	char	*c_joined;

	i = 0;
	len = ft_strslen(buf);
	printf("len: %zu\n", len);
	c_buf = (char **)malloc(sizeof(char *) * (len + 1));
	c_buf[len] = NULL;
	while (i < len)
	{
		if (ft_strncmp(buf[i], "$", 1) && buf[i + 1] != NULL)
			c_buf[i] = ft_strdup(getenv(buf[i + 1]));
		else
			c_buf[i] = ft_strdup(buf[i]);
		printf("%s\n", buf[i]);
		i++;
	}
	c_joined = total_join(c_buf);
	return (c_joined);
}
