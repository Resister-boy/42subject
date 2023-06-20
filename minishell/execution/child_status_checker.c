/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_status_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:57:59 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/18 23:07:34 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	check_exit_status(int child_status, int *signum)
{
	*signum = 0;
	if (WIFSIGNALED(child_status))
	{
		*signum = WTERMSIG(child_status);
		g_exit_status = 128 + WTERMSIG(child_status);
	}
	else if (WIFEXITED(child_status))
		g_exit_status = WEXITSTATUS(child_status);
	return (0);
}
