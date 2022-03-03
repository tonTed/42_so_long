/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/03/03 16:10:22 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/mlx/mlx.h"
# include "mlx_image.h"
# include "errors.h"
# include "map.h"
# include "assets.h"
# include "keyboard.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

/* BONUS */
# include <time.h>
# define COLOR_STR 0xFB9B17
# define MOVE_STR "Moves: "

# define DEBUG 1

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		display;
	t_map		map;
	t_assets	assets;
}			t_vars;

/* BONUS */
typedef struct s_rect
{
	u_int32_t	width;
	u_int32_t	height;
	u_int32_t	x;
	u_int32_t	y;
}			t_rect;

/* initialization */
int			init_map(t_map *map, int fd);
void		init_player(t_map *map, int len);
void		init_mlx_assets(t_vars *vars);

/* assets initialization */
void		init_assets(t_vars *vars);
char		*alloc_asset(void);
u_int32_t	get_index_begin(u_int32_t pos_x, u_int32_t pos_y, t_xpm xpm);
void		set_data_pixel(t_set_data cur_pos, char *dst, t_xpm xpm);

/* graphic functions */
int			draw_frame(t_vars *vars);
int			ignore_color(char *data);
t_img		new_image(void *mlx_ptr, u_int32_t width, u_int32_t height);
t_xpm		new_xpm(void *mlx_ptr, char *path, u_int32_t ratio);
void		set_xpm(t_xpm *xpm, u_int32_t periph, u_int32_t sep,
				u_int32_t size);

/* free utils */
void		free_memory(t_vars *vars);
int			free_exit(t_vars *vars, int code_exit);
int			close_game(void *param);

/* put utils (debug) */
void		put_map(t_map map);
void		put_player(t_player *player);

/* map checker */
char		*get_next_line(int fd);
int			read_map(char *path, t_vars *vars);
int			is_only_wall(char *line);
int			is_col_wall(char *line, size_t i_end);
int			is_valid_map(t_map *map);

/* engine */
void		move_up(t_vars *vars);
void		move_down(t_vars *vars);
void		move_right(t_vars *vars);
void		move_left(t_vars *vars);
bool		end_game(t_vars *vars);
u_int32_t	get_pos_data_map(u_int32_t x, u_int32_t y, u_int32_t width);
bool		cur_char(t_map map, char c);
bool		is_next_move_valid(t_map *map, int step_x, int step_y);
int			key_hook(int key, void *param);

/* BONUS */
void		counter(t_vars *vars);

#endif
