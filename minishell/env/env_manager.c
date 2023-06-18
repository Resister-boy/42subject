/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:00:22 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/18 04:18:58 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_key_value(char *arg, char **key, char **value)
{
	char	*equal_pos;
	int		equal_len;

	equal_pos = ft_strchr(arg, '=');
	if (!equal_pos)
	{
		*key = ft_strdup(arg);
		*value = NULL;
		return (0);
	}
	equal_len = equal_pos - arg;
	*key = ft_substr(arg, 0, equal_len);
	if (!*key)
		return (1);
	*value = ft_substr(arg, equal_len + 1, \
	ft_strlen(arg) - (equal_len + 1));
	if (!*value)
	{
		free(*key);
		return (1);
	}
	return (0);
}

int	change_env_value(t_env_manager *env_manager, char *key, char *value)
{
	t_env	*env;

	env = get_env(env_manager->head, key);
	if (!env)
		return (1);
	if (env->value)
		free(env->value);
	if (!value)
		env->value = NULL;
	else
		env->value = ft_strdup(value);
	return (0);
}

t_env	*make_env(char *arg)
{
	char	*key;
	char	*value;

	if (get_key_value(arg, &key, &value))
		return (NULL);
	return (make_node(key, value));
}

int	add_env(t_env_manager *env_manager, t_env *new_env)
{
	t_env	*last_node;

	if (!new_env)
		return (1);
	if (!env_manager->head)
		env_manager->head = new_env;
	else
	{
		last_node = get_last_node(env_manager->head);
		last_node->next = new_env;
	}
	(env_manager->size)++;
	return (0);
}

int	delete_env(t_env_manager *env_manager, char *key)
{
	t_env	*prev_node;
	t_env	*temp;

	prev_node = NULL;
	temp = env_manager->head;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
		{
			if (temp == env_manager->head)
				env_manager->head = temp->next;
			else
				prev_node->next = temp->next;
			free_node(&temp);
			break ;
		}
		prev_node = temp;
		temp = temp->next;
	}
	(env_manager->size)--;
	return (0);
}

t_env	*get_env(t_env *env, char *key)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	is_valid_env_key(char *key)
{
	int	i;

	if (!key)
		return (0);
	i = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (0);
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
	}
	return (1);
}
