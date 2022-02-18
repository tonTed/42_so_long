/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:35:21 by tonted            #+#    #+#             */
/*   Updated: 2022/02/18 10:06:07 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO : Refactor!!!
void	img_extend_step(char *src, char *dst, size_t steps, size_t ratio)
{
	size_t	i;

	i = 0;
	while (i < ratio)
	{
		ft_memcpy(&dst[i * steps], src, steps);
		ft_memcpy(&dst[i * steps + 192], src, steps);
		ft_memcpy(&dst[i * steps + 192 *2], src, steps);
		i++;
	}
}

void	img_extend_line(t_img src, t_img dst, size_t ratio, size_t rows)
{
	size_t	col;
	size_t	step;

	step = src.length / src.w;
	col = 0;
	while (col < src.w)
	{
		img_extend_step(&src.addr[col * step + rows * src.length], 
			&dst.addr[col * step * ratio + rows * dst.length * ratio], step, ratio);
		col++;
	}
}

t_img	img_extend(t_vars vars, t_img img, unsigned ratio)
{
	t_img 	new_img;
	size_t	rows;

	rows = 0;
	new_img = new_image(vars.ptr, img.w * ratio, img.h * ratio);
	while (rows < img.h)
	{
		img_extend_line(img, new_img, ratio, rows);
		rows++;
	}
	return (new_img);
}