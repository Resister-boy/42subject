/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:47:44 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/19 20:07:50 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	check_s_q(char chr, int *s_quote)
{
	if (chr == '\'' && *s_quote == 1)
		*s_quote = 0;
	else if (chr == '\'' && *s_quote == 0)
		*s_quote = 1;
	return (*s_quote);
}

int	check_d_q(char chr, int *d_quote)
{
	if (chr == '\"' && *d_quote == 1)
		*d_quote = 0;
	else if (chr == '\"' && *d_quote == 0)
		*d_quote = 1;
	return (*d_quote);
}
