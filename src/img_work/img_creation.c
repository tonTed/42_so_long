/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:40:28 by tonted            #+#    #+#             */
/*   Updated: 2022/02/17 22:00:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_image(void *mlx_ptr, unsigned width, unsigned height)
{
	t_img img;

	img.ptr = mlx_new_image(mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.length, &img.endian);
	img.w = width;
	img.h = height;
	return (img);
}

t_img	new_xpm(void *mlx_ptr, char *path)
{
	t_img img;

	img.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.length, &img.endian);
	return (img);
}
