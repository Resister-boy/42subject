/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 03:22:05 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 09:58:52 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execution(t_pipe_manager *p_man, t_env_manager *env_manager)
{
	execute_redirection(p_man);
	if (p_man->head)
	{
		if (p_man->size == 1)
			execute_single_pipe(p_man, env_manager);
		else
			execute_multiple_pipe(p_man, env_manager);
	}
	return (0);
}
