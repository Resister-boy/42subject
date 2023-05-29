/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:36:14 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/18 11:08:44 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_ignore_first_arg(char *arg)
{
	if (ft_strncmp(arg, "--", 3) == 0)
		return (1);
	else
		return (0);
}
