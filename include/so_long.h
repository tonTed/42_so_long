/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/17 22:01:15 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define ASSET_SIZE 16
# define RATIO 3
# define BLOC_SIZE ASSET_SIZE * RATIO
# define _UNIQ_BPP 4

typedef struct	s_map_assets
{
	char	*lt_wall;
	char	*h_wall;
	char	*rt_wall;
	char	*v_wall;
	char	*lb_wall;
	char	*rb_wall;
}				t_map_assets;

typedef	struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_rect
{
	int	w;
	int h;
	int	color;
}			t_rect;


typedef	struct s_vars
{
	void			*ptr;
	void			*win;
	int				w;
	int				h;
	char			*title;
	int				status;
	t_map_assets	ma;
}			t_vars;


char *get_next_line(int fd);

/* image management */
t_img	new_image(void *mlx_ptr, unsigned width, unsigned height);
t_img	new_xpm(void *mlx_ptr, char *path);
void	xpm_to_img(t_img src, t_img dst, int x, int y);
t_img	img_extend(t_vars vars, t_img img, unsigned ratio);
char	*img_get_onset(t_img img, int x, int y);

#endif