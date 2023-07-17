/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:15:50 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/26 17:39:49 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_env(t_env_manager *env_manager)
{
	t_env	*temp;

	if (!env_manager || !env_manager->head)
		return (0);
	temp = env_manager->head;
	while (temp)
	{
		if (temp->value)
			ft_printf(STDOUT_FILENO, "%s=\"%s\"\n", temp->key, temp->value);
		else
			ft_printf(STDOUT_FILENO, "%s\n", temp->key);
		temp = temp->next;
	}
	return (0);
}

static int	export_to_change(t_env_manager *env_manager, char *arg)
{
	t_env	*env_node;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (get_key_value(arg, &key, &value))
		return (0);
	env_node = get_env(env_manager->head, key);
	if (!env_node)
	{
		if (key)
			ft_free((void **)&key);
		if (value)
			ft_free((void **)&value);
		return (0);
	}
	if (env_node->value)
		ft_free((void **)&env_node->value);
	if (key)
		ft_free((void **)&key);
	env_node->value = value;
	return (1);
}

static int	export_to_add(t_env_manager *env_manager, char *arg, int *error)
{
	t_env	*env_node;
	int		current_error;

	env_node = make_env(arg);
	if (!env_node)
		return (1);
	current_error = !is_valid_env_key(env_node->key);
	*error |= current_error;
	if (current_error && free_node(&env_node) \
	&& ft_printf(2, "minishell: export: %s: not a valid identifier\n", arg))
		return (1);
	add_env(env_manager, env_node);
	return (1);
}

int	ft_export(char **args, t_env_manager *env_manager)
{
	int		i;
	int		error;

	if (!args || !*args)
		return (print_env(env_manager));
	i = is_ignore_first_arg(args[0]) - 1;
	if (i > -1 && !args[1])
		return (print_env(env_manager));
	error = 0;
	while (args[++i])
	{
		if (export_to_change(env_manager, args[i]) \
		|| export_to_add(env_manager, args[i], &error))
			continue ;
	}
	return (error);
}
