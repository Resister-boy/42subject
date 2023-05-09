/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:40:31 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/09 13:25:27 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	ft_print_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	ft_print_error(char *error)
{
	write(1, error, ft_strlen(error));
}
