/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:56:29 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 13:07:01 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_envname(char *str, size_t *idx)
{
	size_t	start;

	start = (*idx) + 1;
	if (!str[start] || !ft_isalpha(str[start]) || str[start] == '_')
		return (ft_strdup(""));
	while (str[(*idx)] && !ft_isspace(str[(*idx)]) && str[(*idx)] != '$' && \
	(ft_isalpha(str[(*idx)]) || ft_isdigit(str[(*idx)]) || str[(*idx)] == '_'))
		(*idx)++;
	return (ft_substr(str, start, (*idx)));
}

static size_t	get_dollar(char *str)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[0] != '$')
				num++;
			num++;
		}
		i++;
	}
	return (num);
}

// 환경변수명 규칙
// 1번째 문자로 영문자,언더바 가능 | 숫자와 특수문자 올 수 없음
// 2번째 문자부터 영문자, 언더바, 숫자 가능 | 특수문자 올 수 없음
// 위 규칙에 따라 아래를 수행
// $ 이후 첫번째 문자로 숫자와 특수문자가 나오면 확장 안함
// 두번째 문자부터 특수문자가 나오면 해당 문자 앞의까지만 환경변수로 침
void	expand_env_quote(char *str, t_tmp *temp)
{
	size_t	i;
	size_t	k;
	size_t	len;
	size_t	start;
	char	**buf;

	i = 0;
	k = 0;
	len = get_dollar(str);
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	printf("buflen: %zu\n", len);
	buf[len] = NULL;
	while (str[i])
	{
		if (str[i] && str[i++] == '$')
		{
			start = i;
			while (str[i] && !ft_isspace(str[i]) && str[i] != '$')
				i++;
			buf[k] = getenv(ft_substr(str, start, i));
		}
		k++;
	}
	temp->args = total_join(buf);
}

void	expand_env(char *str, t_pipe *node)
{
	size_t	i;
	size_t	k;
	size_t	len;
	size_t	start;
	char	**buf;

	i = 0;
	k = 0;
	len = get_dollar(str);
	buf = (char **)malloc(sizeof(char *) * (len + 1));
	buf[len] = NULL;
	while (str[i])
	{
		if (str[i] && str[i++] == '$')
		{
			start = i;
			while (str[i] && !ft_isspace(str[i]) && str[i] != '$')
				i++;
			buf[k] = getenv(ft_substr(str, start, i));
		}
		k++;
	}
	connect_cmd_tmp(buf, node);
}
