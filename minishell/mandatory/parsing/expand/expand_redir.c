/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:14:37 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/06 13:07:07 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_ambiguous(char *str, char *file)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (str[i])
	{
		status = check_is_quote(str[i], status);
		if (is_valid_dollar(str, i))
			break ;
		i++;
	}
	if (status == NO_QUOTE && (is_all_space(file) || ft_strlen(file) == 0))
		return (1);
	return (0);
}

void	handle_redir_ambiguous(t_io *redir, char *str)
{
	redir->type = REDIR_AMBIGUOUS;
	redir->filename = ft_strdup(str);
}

char	**handle_redir_copy_util(char *str, int len)
{
	int		i;
	int		j;
	char	**buf;

	i = 0;
	j = 0;
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	while (str[i])
	{
		if (str[i] && str[i] == '\'')
			i = handle_redir_str_sq(str, buf, i, &j);
		else if (str[i] && str[i] == '\"')
			i = handle_redir_str_dq(str, buf, i, &j);
		else
			i = handle_redir_str_no(str, buf, i, &j);
	}
	return (buf);
}

void	handle_redir_copy(char *str, t_io *redir)
{
	int		len;
	char	**buf;
	char	*file;

	len = get_quote_count(str);
	buf = handle_redir_copy_util(str, len);
	file = total_join(buf);
	free_double_str(&buf);
	redir->filename = file;
}

void	handle_redir_expand(char *str, t_env_manager *e_man, t_io *redir)
{
	int		len;
	char	**buf;
	char	*file;

	len = get_quote_count(str);
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	handle_quote_util(str, buf, e_man);
	file = total_join(buf);
	free_double_str(&buf);
	if (check_is_ambiguous(str, file))
	{
		ft_free((void **)&file);
		handle_redir_ambiguous(redir, str);
		return ;
	}
	redir->filename = file;
}
