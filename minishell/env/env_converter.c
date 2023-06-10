/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:29:00 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/30 20:14:02 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	free_for_exception(char ***envp, int i)
{
	while (--i)
		free((*envp)[i]);
	free(*envp);
	return (1);
}

static int	make_env_arr(t_env *temp, char **envp, int *i)
{
	char	*env;
	char	*env2;

	env = ft_strjoin(temp->key, "=");
	if (!env && free_for_exception(&envp, *i))
		return (0);
	env2 = ft_strjoin(env, temp->value);
	if (!env2 && free_for_exception(&envp, *i))
	{
		free(env);
		return (0);
	}
	envp[(*i)++] = env2;
	return (1);
}

int	free_all_node(t_env	*head)
{
	t_env	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
	return (1);
}

char	**env_list_to_arr(t_env_manager *env_manager)
{
	char	**envp;
	t_env	*temp;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (env_manager->size + 1));
	if (!envp)
		return (NULL);
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

int	env_arr_to_list(t_env_manager *env_manager, char **envp)
{
	int		i;
	t_env	*new_env;

	i = -1;
	while (envp[++i])
	{
		new_env = make_env(envp[i]);
		if (!new_env && free_all_node(env_manager->head))
			return (1);
		add_env(env_manager, new_env);
	}
	return (0);
}
