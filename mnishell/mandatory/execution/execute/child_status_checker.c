/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_status_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:57:59 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:02 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit_status(int child_status, int *signum)
{
	*signum = 0;
	if (WIFSIGNALED(child_status))
	{
		*signum = WTERMSIG(child_status);
		g_exit_status = 128 + WTERMSIG(child_status);
	}
	else
		g_exit_status = WEXITSTATUS(child_status);
	return (0);
}
