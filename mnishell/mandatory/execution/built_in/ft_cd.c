/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:37:29 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/10 15:55:57 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	move_to_home(t_env_manager *env_manager)
{
	t_env	*home_env;
	char	*current_path;

	home_env = get_env(env_manager->head, "HOME");
	if (!home_env && ft_printf(2, "minishell: cd: HOME not set\n"))
		return (1);
	current_path = getcwd(NULL, 0);
	if (chdir(home_env->value))
		return (ft_perror_join("minishell: cd: ", home_env->value));
	change_env_value(env_manager, "OLDPWD", current_path);
	if (current_path)
		ft_free((void **)&current_path);
	change_env_value(env_manager, "PWD", home_env->value);
	return (0);
}

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
	old_pwd_path = old_pwd->value;
	pwd_path = pwd->value;
	if (chdir(old_pwd_path))
		return (ft_perror_join("minishell: cd: ", old_pwd_path));
	temp = old_pwd_path;
	old_pwd_path = pwd_path;
	pwd_path = temp;
	old_pwd->value = old_pwd_path;
	pwd->value = pwd_path;
	return (ft_pwd());
}

static int	move_to_arg(char *arg, t_env_manager *env_manager)
{
	char	*current_path;

	if (access(arg, F_OK))
		return (ft_perror_join("minishell: cd: ", arg));
	current_path = getcwd(NULL, 0);
	if (chdir(arg))
		return (ft_perror_join("minishell: cd: ", arg));
	change_env_value(env_manager, "OLDPWD", current_path);
	if (current_path)
		ft_free((void **)&current_path);
	current_path = getcwd(NULL, 0);
	change_env_value(env_manager, "PWD", current_path);
	ft_free((void **)&current_path);
	return (0);
}

int	ft_cd(char **args, t_env_manager *env_manager)
{
	int		i;

	if (!args || !args[0])
		return (move_to_home(env_manager));
	i = is_ignore_first_arg(args[0]);
	if (!args[i])
		return (move_to_home(env_manager));
	else if (ft_strncmp(args[i], "-", 2) == 0)
		return (ft_cd_oldpwd(env_manager));
	return (move_to_arg(args[i], env_manager));
}
