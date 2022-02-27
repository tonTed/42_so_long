/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 17:40:07 by tonted           ###   ########.fr       */
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

# define DEBUG 1

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		display;
	t_map		map;
	t_assets	assets;
}			t_vars;

char *get_next_line(int fd);

int	read_map(char *path, t_vars *vars);

int		init_map(t_map *map, int fd);
void	init_player(t_map *map, int len);

/* assets initialization */
void		init_assets(t_vars *vars);
char		*alloc_asset();
unsigned	get_index_begin(unsigned pos_x, unsigned pos_y, t_xpm xpm);
void		set_data_pixel(t_set_data cur_pos, char *dst, t_xpm xpm);

int		draw_frame(t_vars *vars);

void	free_memory(t_vars *vars);
int		free_exit(t_vars *vars, int code_exit);

void	put_map(t_map map);
void	put_player(t_player *player);

int	is_only_wall(char *line);
int	is_col_wall(char *line, size_t i_end);
int	is_valid_map(t_map *map);

t_img	new_image(void *mlx_ptr, unsigned width, unsigned height);
t_xpm	new_xpm(void *mlx_ptr, char *path, unsigned ratio);
void	set_xpm(t_xpm *xpm, unsigned periph, unsigned sep, unsigned size);

void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
bool	end_game(t_vars *vars);

# include <stdio.h>

#endif
