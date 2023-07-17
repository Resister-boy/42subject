/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:27:17 by seonghle          #+#    #+#             */
/*   Updated: 2023/06/16 08:18:23 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	output_redirection(char *outfile)
{
	return (open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644));
}

int	input_redirection(char *infile)
{
	return (open(infile, O_RDONLY));
}

int	append_redirection(char *outfile)
{
	return (open(outfile, O_CREAT | O_APPEND | O_WRONLY, 0644));
}
