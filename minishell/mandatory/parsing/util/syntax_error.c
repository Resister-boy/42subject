/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:57:49 by jaehulee          #+#    #+#             */
/*   Updated: 2023/07/10 00:24:24 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unexpected_token_error(char *token)
{
	g_exit_status = 258;
	ft_printf(1, "minishell: syntax error near unexpected token '%s'\n", token);
	return (-1);
}
