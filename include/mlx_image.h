/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:13 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 09:15:38 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

typedef	struct s_img
{
	void		*ptr;
	char		*data;
	unsigned	bpp;
	unsigned	length;
	int			endian;
	unsigned	w;
	unsigned	h;
}			t_img;

typedef struct s_xpm
{
	t_img		img;
	unsigned	ratio;
	unsigned	periph;
	unsigned	sep;
	unsigned	size;
}		t_xpm;

typedef struct s_set_data
{
	unsigned	i;
	unsigned	row_origin;
	unsigned	col_origin;
	unsigned	row_new;
	unsigned	col_new;
}			t_set_data;

#endif