/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_status_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:57:59 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 08:59:10 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	check_exit_status(int child_status)
{
	if (WIFSIGNALED(child_status))
	{
		if (WTERMSIG(child_status) == 3)
			ft_putstr_fd("Quit: 3", STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		g_exit_status = 128 + WTERMSIG(child_status);
	}
	else if (WIFEXITED(child_status))
		g_exit_status = WEXITSTATUS(child_status);
	return (0);
}
