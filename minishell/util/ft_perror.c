/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:52:29 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/18 21:48:04 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

int	ft_perror_join(char *prefix, char *postfix)
{
	char	*temp;

	if (!prefix || !postfix)
		return (1 & \
			ft_printf(2, "ft_prerror_join error [%s] [%s]\n", prefix, postfix));
	temp = ft_strjoin(prefix, postfix);
	perror(temp);
	free(temp);
	return (1);
}

int	ft_perror(char *cause)
{
	if (!cause)
		perror("minishell");
	else
		perror(cause);
	return (1);
}
