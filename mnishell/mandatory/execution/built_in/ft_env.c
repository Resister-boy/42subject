/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:26:02 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/23 02:00:29 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env_manager *env_manager)
{
	t_env	*temp;

	if (!env_manager->head)
		return (0);
	temp = env_manager->head;
	while (temp)
	{
		if (temp->value)
			ft_printf(STDOUT_FILENO, "%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
	return (0);
}
