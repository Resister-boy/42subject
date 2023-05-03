/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:30:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/03 17:55:48 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_WINDOW_CLOSE		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_D		2
# define KEY_S		1
# define KEY_A		0

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

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
	void		*mlx_ptr;
	void		*win_ptr;
	void		*w_img;
	void		*p_img;
	void		*g_img;
	void		*e_img;
	void		*c_img;
	size_t		map_x;
	size_t		map_y;
	t_player	p_location;
	int			player;
	int			move;
	int			ground;
	int			wall;
	int			collection;
	int			escape;
}	t_stat;

// so_long.c
void	so_long(t_stat *stat);
void	ft_init_game(t_stat *stat, void *mlx_ptr, void *win_ptr);
int		ft_init_stat(t_stat *stat, char *filename);

// ft_parse_utils.c
int		ft_parse_map(t_stat *stat);
void	ft_dup_map_line(char *map, t_stat *stat);
t_map	*ft_new_line(char *map_line);
int		ft_is_collect_file(char *filename);
void	ft_translate_arr(t_stat *stat);

// ft_free_utils.c 
void	ft_free_map_list(t_stat *stat);
void	ft_free_map_arr(t_stat *stat, char ***strs);

// ft_check_utils_1.c
int		ft_check_map(t_stat *stat);
int		ft_is_map_square(t_stat *stat);
int		ft_is_size_enough(t_stat *stat);
int		ft_is_rounded_wall(t_stat *stat);
int		ft_check_map_symbol(t_stat *stat);

// ft_check_utils_2.c
int		ft_check_symbol_utils(t_stat *stat, char *line, size_t row);
int		ft_count_symbol(t_stat *stat, char symbol, int col, int row);
int		ft_is_both_end_wall(char *str);
int		ft_is_all_wall(char *str);

// ft_check_utils_3.c 
int		ft_is_map_playable(t_stat *stat);
int		ft_search_map(t_stat *stat, char **map, int p_y, int p_x);
int		ft_search_util(t_stat *stat, char **map);

// ft_print_utils_1.c
void	ft_print_message(char *str);

// ft_play_utils.c
void	ft_render_all_img(t_stat *stat, int row, int col);
void	ft_draw_total_map(t_stat *stat);
int		ft_key_press(int keycode, t_stat *stat);
void	ft_render_single_img(t_stat *stat, void *img, int flag);
int		ft_is_wall(t_stat *stat, int p_y, int p_x);

// ft_play_utils_2.c
void	ft_finish_game(t_stat *stat);
void	ft_move_player(t_stat *stat, int p_y, int p_x);
int		ft_check_escapable(t_stat *stat);
void	ft_is_not_escape(t_stat *stat, int p_y, int p_x);
void	ft_not_allow_escape(t_stat *stat, int p_y, int p_x);

// ft_play_utils_3.c
int		ft_finish_program(t_stat *stat);
void	ft_print_move(t_stat *stat);
void	ft_print_decimal(int n, char *base);

// lib
void	ft_lstadd_back(t_stat *stat, t_map *new);
t_map	*ft_lstlast(t_map *map);
size_t	ft_lstsize(t_map *map);
char	*ft_strdup(char *str);
size_t	ft_strlen(char *str);
size_t	ft_total_len(char **strs);
char	**ft_strsdup(t_stat *stat);

#endif