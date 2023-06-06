/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:14:37 by jaehulee          #+#    #+#             */
/*   Updated: 2023/06/06 04:31:37 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env_redir(char *str)
{
	char	*expanded;

	expanded = getenv(str);
	return (expanded);
}

void	handle_redir_expand(char *str, t_io *redir)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	dollar;
	char	**buf;
	char	*file;

	i = 0;
	j = 0;
	dollar = get_dollar_count(str);
	while (str[i] != '\0' && str[i] == '\"')
		i++;
	printf("dollar: %zu\n", dollar);
	if (str[i] != '$')
		dollar += 1;
	printf("dollar: %zu\n", dollar);
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	buf = (char **)malloc(sizeof(char *) * (dollar + 1));
	buf[dollar] = NULL;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == '\"')
			i++;
		start = i;
		while (str[i] && str[i] != '$')
			i++;
		if (start < i)
		{
			buf[j] = ft_substr(str, start, i - start);
			j++;
		}
		if (is_valid_dollar(str, i))
		{
			i++;
			start = i;
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				i++;
			buf[j] = expand_env_redir(ft_substr(str, start, i - start));
			j++;
		}
	}
	file = total_join(buf);
	if (is_all_space(file) || ft_strlen(file) == 0)
	{
		redir->type = AMBIGUOUS_REDIR;
		redir->filename = str;
		return ;
	}
	redir->filename = file;
}
