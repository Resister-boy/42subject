/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:22:05 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:13 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execution(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	g_exit_status = execute_redirection(p_man, env_manager);
	if (p_man->head && g_exit_status == 0)
	{
		if (p_man->size == 1)
			execute_single_pipe(p_man, env_manager);
		else
			execute_multiple_pipe(p_man, env_manager);
	}
	return (0);
}
