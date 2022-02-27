/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:40:28 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 08:43:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_image(void *mlx_ptr, unsigned width, unsigned height)
{
	t_img img;

	img.ptr = mlx_new_image(mlx_ptr, width, height);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.length, &img.endian);
	img.w = width;
	img.h = height;
	return (img);
}

t_xpm	new_xpm(void *mlx_ptr, char *path, unsigned ratio)
{
	t_xpm xpm;

	xpm.img.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &xpm.img.w, &xpm.img.h);
	xpm.img.data = mlx_get_data_addr(xpm.img.ptr, &xpm.img.bpp, &xpm.img.length,
		&xpm.img.endian);
	xpm.ratio = ratio;
	return (xpm);
}

void	set_xpm(t_xpm *xpm, unsigned periph, unsigned sep, unsigned size)
{
	xpm->periph = periph;
	xpm->sep = sep;
	xpm->size = size;
}