#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "./get_next_line/get_next_line.h"

typedef	struct s_map
{
	char			*map_line;
	struct s_map	*prev;
	struct s_map	*next;
} t_map;

typedef struct s_stat
{
	int		fd;
	t_map	*map;
	int		escape_count;
	int		start_count;
	int		collect_count;
	int		win_width;
	int		win_height;
	int		move;
	int		player_x;
	int		player_y;
	int		ground;
	int		wall;
	int		collection;
	int		escape;
	int		player;
}	t_stat;

void	so_long(t_stat *stat);
void	ft_init_stat(t_stat *stat);
void	ft_parse_map(t_stat *stat);
void	ft_dup_map_line(char *map, t_stat *stat);
t_map	*ft_new_line(char *map_line);

// ft_free_utils.c 
void	ft_free_map(t_stat *stat);

// ft_check_utils_1.c
int 	ft_check_map(t_stat *stat);

// ft_print_utils.c
void  	ft_print_message(char *str);

// lib
void		ft_lstadd_back(t_stat *stat, t_map *new);
t_map		*ft_lstlast(t_map *map);
size_t	ft_lstsize(t_map *map);
char		*ft_strdup(char *str);
size_t  ft_strlen(char *str);
size_t	ft_total_len(char **strs);


int 		ft_is_map_square(t_map *map); // map이 직사각형인지
int 		ft_is_size_enough(t_map *map); // 가로 * 세로가 12 이상인지
int 		ft_is_rounded_wall(t_map *map); // map이 벽으로 둘러싸여있는지 
int			ft_is_both_end_wall(char *str); // dependencies
int			ft_is_all_wall(char *str); // dependencies
int 		ft_is_other_symbol(t_map *map); // character, collection, escape, wall 이외에 다른 심볼이 있는지
int 		ft_is_symbol_ok(t_stat *stat); // character, collection, escape이 존재하는지
void		ft_count_flag(t_stat *stat, char symbol);

// int ft_is_fe_ber(); // map 파일의 확장자가 .ber인지
// int ft_is_map_playable(); // character가 collection, escape에 점근할 수 있는지

void	ft_print_map(t_stat *stat);

#endif