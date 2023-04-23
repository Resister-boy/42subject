/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:30:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/20 05:11:42 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"

typedef	struct s_map
{
	char			*map_line;
	struct s_map	*next;
} t_map;


typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_stat
{
	int			fd;
	char		**map_arr;
	t_map		*map_list;
	int			map_size;
	int			map_x;
	int			map_y;
	t_player	p_location;
	int			win_width;
	int			win_height;
	int			player;
	int			move;
	int			ground;
	int			wall;
	int			collection;
	int			escape;
	int			t_collection;
	int			t_escape;
}	t_stat;

// so_long.c
void	so_long(t_stat *stat);
int		ft_init_stat(t_stat *stat, char *filename);

// ft_parse_utils.c
void	ft_parse_map(t_stat *stat);
void	ft_dup_map_line(char *map, t_stat *stat);
t_map	*ft_new_line(char *map_line);
int		ft_is_collect_file(char *filename);
void	ft_translate_arr(t_stat *stat);

// ft_free_utils.c 
void	ft_free_map_list(t_stat *stat);
void	ft_free_map_arr(t_stat *stat, char **strs);

// ft_check_utils_1.c
int 	ft_check_map(t_stat *stat);
int		ft_is_map_square(t_stat *stat);
int		ft_is_size_enough(t_stat *stat);
int		ft_is_rounded_wall(t_stat *stat);
int		ft_check_map_symbol(t_stat *stat);

// ft_check_utils_2.c
int		ft_check_symbol_utils(t_stat *stat, char *line, size_t row);
int		ft_count_symbol(t_stat *stat, char symbol, size_t col, size_t row);
int 	ft_is_both_end_wall(char *str);
int 	ft_is_all_wall(char *str);

// ft_check_utils_3.c 
int 	ft_is_map_playable(t_stat *stat);
int 	ft_search_map(t_stat *stat, char **map, int p_y, int p_x);
int		ft_search_util(t_stat *stat, char **map);

// ft_print_utils.c
void  	ft_print_message(char *str);

// lib
void		ft_lstadd_back(t_stat *stat, t_map *new);
t_map		*ft_lstlast(t_map *map);
size_t	ft_lstsize(t_map *map);
char		*ft_strdup(char *str);
size_t  ft_strlen(char *str);
size_t	ft_total_len(char **strs);
char		**ft_strsdup(t_stat *stat);

// int ft_is_map_playable(); // character가 collection, escape에 점근할 수 있는지

void	ft_print_map_list(t_stat *stat);
void	ft_print_map_arr(t_stat *stat, char **strs);
#endif