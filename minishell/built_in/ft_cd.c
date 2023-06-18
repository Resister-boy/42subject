/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:37:29 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/18 02:50:56 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cd_oldpwd(t_env_manager *env)
{
	t_env	*old_pwd;
	t_env	*pwd;
	char	*temp;
	char	*pwd_path;
	char	*old_pwd_path;

	old_pwd = get_env(env->head, "OLDPWD");
	if ((!old_pwd || !old_pwd->value) && \
	ft_printf(2, "minishell: cd: OLDPWD not set\n"))
		return (1);
	pwd = get_env(env->head, "PWD");
	if (!pwd)
		return (0);
	if (!*old_pwd->value)
	{
		ft_printf(1, "\n");
		return (0);
	}
	old_pwd_path = old_pwd->value;
	pwd_path = pwd->value;
	if (chdir(old_pwd_path))
	{
		perror("cd");
		return (1);
	}
	temp = old_pwd_path;
	old_pwd_path = pwd_path;
	pwd_path = temp;
	old_pwd->value = old_pwd_path;
	pwd->value = pwd_path;
	return (0);
}

static int	move_to_home(t_env_manager *env_manager)
{
	t_env	*env;
	char	*current_path;

	env = get_env(env_manager->head, "HOME");
	if (!env && printf("minishell: cd: HOME not set\n"))
		return (1);
	current_path = getcwd(NULL, 0);
	if (chdir(env->value) || \
	change_env_value(env_manager, "OLDPWD", current_path))
		free(current_path);
	change_env_value(env_manager, "PWD", getcwd(NULL, 0));
	return (0);
}

int	ft_cd(char **args, t_env_manager *env_manager)
{
	int		i;
	char	*current_path;

	if (!args || !args[0])
		return (move_to_home(env_manager));
	i = is_ignore_first_arg(args[0]);
	if (!args[i])
		return (move_to_home(env_manager));
	else if (ft_strncmp(args[i], "-", 2) == 0)
		return (ft_cd_oldpwd(env_manager));
	else
	{
		if (!access(args[i], F_OK))
		{
			current_path = getcwd(NULL, 0);
			if (!current_path || chdir(args[i]))
			{
				if (current_path)
					free(current_path);
				perror("cd");
				return (1);
			}
			change_env_value(env_manager, "OLDPWD", current_path);
			free(current_path);
			change_env_value(env_manager, "PWD", getcwd(NULL, 0));
		}
		else
			return (1 && \
			printf("minishell: cd: %s: No such file or directory\n", args[i]));
	}
	return (0);
}
