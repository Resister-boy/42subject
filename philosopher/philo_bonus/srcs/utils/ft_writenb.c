/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:52:13 by francoma          #+#    #+#             */
/*   Updated: 2023/03/07 13:18:08 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	_ft_writenb(char **dst, unsigned int nb)
{
	if (nb > 9)
	{
		_ft_writenb(dst, nb / 10);
	}
	**dst = nb % 10 + '0';
	(*dst)++;
	**dst = '\0';
}

static void	ft_writenb(char *dst, unsigned int nb)
{
	_ft_writenb(&dst, nb);
}

void	ft_prefixed_nb(char *dst, char *prefix, unsigned int nb)
{
	size_t	prefix_len;

	prefix_len = ft_strlen(prefix);
	ft_memcpy(dst, prefix, prefix_len);
	ft_writenb(dst + prefix_len, nb);
}
