/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:52:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 13:28:13 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_print_cmd(t_pipe *pipe)
{
	t_cmd	*cmd;

	cmd = pipe->cmds;
	while (cmd != NULL)
	{
		printf("%s\n", cmd->cmd);
		cmd = cmd->next;
	}
}
