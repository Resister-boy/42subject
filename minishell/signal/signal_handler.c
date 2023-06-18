/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:22:29 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 07:35:26 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	newline_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

void	heredoc_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	exit(1);
}

void	ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}

void	heredoc_parent_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	g_exit_status = 1;
}
