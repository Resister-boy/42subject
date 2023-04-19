/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:35:02 by jaehulee          #+#    #+#             */
/*   Updated: 2023/03/23 15:27:03 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char **backup);
char	*ft_strjoin_str(char **backup, char *buf);
char	*ft_create_line(char **backup);
int		ft_check_ln(char *str);
char	*ft_store_backup(char **backup);
void	ft_free_backup(char **backup);
void	*ft_calloc(size_t count, size_t size, char **backup);
size_t	ft_stringlen(char *str);
size_t	ft_strlen_ln(char *str);

#endif