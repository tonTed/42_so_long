/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:40:28 by tonted            #+#    #+#             */
/*   Updated: 2022/02/07 20:55:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_image(t_vars vars, unsigned width, unsigned height)
{
	t_img img;

	img.ptr = mlx_new_image(vars.ptr, width, height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.length, &img.endian);
	img.w = width;
	img.h = height;
	return (img);
}

t_img	new_xpm(t_vars vars, char *path)
{
	t_img img;

	img.ptr = mlx_xpm_file_to_image(vars.ptr, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.length, &img.endian);
	return (img);
}
