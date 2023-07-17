/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:29:52 by chbaek            #+#    #+#             */
/*   Updated: 2022/11/28 09:37:52 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_word_array(char const *s, char c, size_t *word_count);
static char	*alloc_word(char const **s, char c);
static void	exception_handling(char **result, size_t i);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	word_count;

	if (!s)
		return (0);
	result = alloc_word_array(s, c, &word_count);
	if (!result)
		return (0);
	i = 0;
	while (i < word_count)
	{
		result[i] = alloc_word(&s, c);
		if (!result[i])
		{
			exception_handling(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}

static char	**alloc_word_array(char const *s, char c, size_t *word_count)
{
	size_t	i;
	int		flag;
	char	**result;

	*word_count = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (flag == 0)
				(*word_count)++;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (*word_count + 1));
	if (!result)
		return (0);
	result[*word_count] = 0;
	return (result);
}

static char	*alloc_word(char const **s, char c)
{
	size_t		char_count;
	size_t		i;
	const char	*start_word;
	char		*word;

	char_count = 0;
	while (**s && **s == c)
		(*s)++;
	start_word = *s;
	while (**s && **s != c)
	{
		char_count++;
		(*s)++;
	}
	word = (char *)malloc(sizeof(char) * (char_count + 1));
	if (!word)
		return (0);
	word[char_count] = 0;
	i = 0;
	while (i < char_count)
	{
		word[i] = start_word[i];
		i++;
	}
	return (word);
}

static void	exception_handling(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(result[j++]);
	free(result);
}
