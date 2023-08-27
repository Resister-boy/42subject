/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:43:02 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 15:58:12 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>

size_t	timeval_to_ms(struct timeval tv);
void	set_program_start_time(void);
size_t	ms_since_program_start(void);
size_t	now(void);

#endif