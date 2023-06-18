/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:29:00 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/18 05:50:06 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	make_env_arr(t_env *temp, char **envp, int *i)
{
	char	*env;
	char	*env2;

	env = ft_strjoin(temp->key, "=");
	env2 = ft_strjoin(env, temp->value);
	free(env);
	envp[(*i)++] = env2;
	return (1);
}

int	free_env(t_env_manager *env_manager)
{
	t_env	*temp;

	while (env_manager->head)
	{
		temp = env_manager->head;
		env_manager->head = env_manager->head->next;
		free(temp->key);
		temp->key = NULL;
		if (temp->value)
		{
			free(temp->value);
			temp->value = NULL;
		}
		free(temp);
		temp = NULL;
	}
	env_manager->size = 0;
	return (0);
}

char	**env_list_to_arr(t_env_manager *env_manager)
{
	char	**envp;
	t_env	*temp;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (env_manager->size + 1));
	envp[env_manager->size] = NULL;
	temp = env_manager->head;
	i = 0;
	while (temp)
	{
		if (!make_env_arr(temp, envp, &i))
			return (NULL);
		temp = temp->next;
	}
	return (envp);
}

static int	is_num(char *arg)
{
	int	i;

	if (!arg || !*arg)
		return (0);
	if (arg[0] == '-' || arg[0] == '+')
		i = 1;
	i = 0;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}

int	env_arr_to_list(t_env_manager *env_manager, char **envp)
{
	int		i;
	int		exist_oldpwd;
	int		exist_shlvl;
	char	*new_value;
	t_env	*new_env;

	i = -1;
	exist_oldpwd = 0;
	exist_shlvl = 0;
	while (envp[++i])
	{
		new_env = make_env(envp[i]);
		if (!new_env && !free_env(env_manager))
			return (1);
		if (!ft_strncmp(new_env->key, "OLDPWD", 7))
			exist_oldpwd = 1;
		else if (!ft_strncmp(new_env->key, "SHLVL", 6))
		{
			exist_shlvl = 1;
			if (!new_env->value || !is_num(new_env->value))
				new_value = ft_itoa(1);
			else
				new_value = ft_itoa(ft_atoi(new_env->value) + 1);
			free(new_env->value);
			new_env->value = new_value;
		}
		add_env(env_manager, new_env);
	}
	if (!exist_oldpwd)
		add_env(env_manager, make_env("OLDPWD"));
	if (!exist_shlvl)
		add_env(env_manager, make_env("SHLVL=1"));
	return (0);
}
