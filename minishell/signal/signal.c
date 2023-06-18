/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:21:34 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 07:36:06 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	set_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_newline_signal(void)
{
	t_termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_heredoc_signal(void)
{
	signal(SIGINT, heredoc_ctrl_c);
	// signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_parent(void)
{
	signal(SIGINT, heredoc_parent_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal(void)
{
	t_termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
