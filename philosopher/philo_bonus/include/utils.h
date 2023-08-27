/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:44:47 by francoma          #+#    #+#             */
/*   Updated: 2023/03/08 10:00:52 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <stdio.h>
# include "philo.h"

void	print_msg(sem_t *lock, char *format, ssize_t id);
void	print_last_msg(sem_t *lock, char *format, ssize_t id);

size_t	ft_strlen(const char *s);
void	ft_prefixed_nb(char *dst, char *prefix, unsigned int nb);
size_t	ft_atost(const char *str);

int		ft_issize_t(char *str);
int		ft_isspace(char c);
int		ft_isdigit(int c);

void	*ft_calloc(size_t count, size_t size);
int		ft_has_val(int *arr, int len, int val);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_putstr_fd(char *s, int fd);
void	exit_error(char *msg);

#endif