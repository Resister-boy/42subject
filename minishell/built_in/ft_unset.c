/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:54:45 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/26 17:06:49 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char **args, t_env_manager *env_manager)
{
	int	i;
	int	error;
	int	current_error;

	error = 0;
	if (!args || !*args)
		return (error);
	i = is_ignore_first_arg(args[0]) - 1;
	while (args[++i])
	{
		current_error = !is_valid_env_key(args[i]);
		error |= current_error;
		if (current_error \
		&& printf("minishell: unset: %s: not a valid identifier\n", args[i]))
			continue ;
		delete_env(env_manager, args[i]);
	}
	return (error);
}
