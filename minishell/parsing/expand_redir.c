/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:14:37 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/12 16:48:08 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*expand_env_redir(t_env_manager *e_man, char *str)
{
	t_env	*expanded;

	expanded = get_env(e_man->head, str);
	return (expanded);
}

void	handle_REDIR_AMBIGUOUS(t_io *redir, char *str)
{
	redir->type = REDIR_AMBIGUOUS;
	redir->filename = str;
}

static void	handle_expand_redir_util(char *str, size_t idx, char **buf, \
t_env_manager *e_man)
{
	size_t	i;
	size_t	start;
	t_env	*env;

	i = 0;
	while (str[idx] != '\0')
	{
		while (str[idx] != '\0' && str[idx] == '\"')
			idx++;
		start = idx;
		while (str[idx] && str[idx] != '$')
			idx++;
		if (start < idx)
			buf[i++] = ft_substr(str, start, idx - start);
		if (is_valid_dollar(str, idx))
		{
			idx++;
			start = idx;
			while (str[idx] && (ft_isalnum(str[idx]) || str[idx] == '_'))
				idx++;
			env = expand_env_redir(e_man, ft_substr(str, start, idx - start));
			handle_env_result(env, buf, i);
			i++;
		}
	}
}

void	handle_redir_expand(char *str, t_env_manager *e_man, t_io *redir)
{
	size_t	i;
	size_t	dollar;
	char	**buf;
	char	*file;

	i = 0;
	dollar = get_dollar_count(str);
	while (str[i] != '\0' && str[i] == '\"')
		i++;
	if (str[i] != '$')
		dollar += 1;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	handle_expand_redir_util(str, i, buf, e_man);
	file = total_join(buf);
	if (is_all_space(file) || ft_strlen(file) == 0)
	{
		handle_REDIR_AMBIGUOUS(redir, str);
		return ;
	}
	redir->filename = file;
}
