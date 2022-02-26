/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/25 20:38:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/mlx/mlx.h"
# include "mlx_image.h"
# include "errors.h"
# include "map.h"
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

}			t_vars;

char *get_next_line(int fd);

int	read_map(char *path, t_vars *vars);

void	free_memory(t_vars *vars);

void	print_map(t_map map);

int	is_only_wall(char *line);
int	is_col_wall(char *line, size_t i_end);
int	is_valid_map(t_map *map);

# include <stdio.h>

#endif
