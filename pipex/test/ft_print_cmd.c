/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:52:12 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 17:04:18 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_print_cmd(t_pipe *pip)
{
	t_cmd	*cmd;

	cmd = pip->cmds;
	while (cmd != NULL)
	{
		printf("%s\n", cmd->cmd);
		printf("%s\n", cmd->op);
		cmd = cmd->next;
	}
}
