/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:13 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 20:04:23 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

typedef struct s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			length;
	int			endian;
	u_int32_t	w;
	u_int32_t	h;
}			t_img;

typedef struct s_xpm
{
	t_img		img;
	u_int32_t	ratio;
	u_int32_t	periph;
	u_int32_t	sep;
	u_int32_t	size;
}		t_xpm;

typedef struct s_set_data
{
	u_int32_t	i;
	u_int32_t	row_origin;
	u_int32_t	col_origin;
	u_int32_t	row_new;
	u_int32_t	col_new;
}			t_set_data;

#endif