/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 23:07:40 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/mlx/mlx.h"
# include "mlx_image.h"
# include "errors.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# define DEBUG 1

typedef struct s_map
{
	unsigned	w;
	unsigned	h;
	char		*data;
}			t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		display;
	t_map		map;

}			t_vars;

char *get_next_line(int fd);

int	read_map(char *path, t_vars *vars);

# include <stdio.h>

#endif
