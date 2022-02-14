/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:25:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/10 07:37:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define SIZE 16

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
	void	*ptr;
	void	*win;
	int		w;
	int		h;
	char	*title;
	int		status;
}			t_vars;

char *get_next_line(int fd);

t_img	new_image(t_vars vars, unsigned width, unsigned height);
t_img	new_xpm(t_vars vars, char *path);
t_img	img_extend(t_vars vars, t_img img, unsigned ratio);

#endif