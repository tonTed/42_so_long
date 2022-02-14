/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:35:21 by tonted            #+#    #+#             */
/*   Updated: 2022/02/12 18:13:09 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*img_get_onset(t_img img, int x, int y)
{
	return ((char *)(img.addr + (y * img.length + x * (img.bpp / 8))));
}

void	img_cpy_line(char *src, char *dst, size_t len)
{
	size_t i;

	i = 0;
	ft_memcpy(dst, src, len);
}

void	xpm_to_img(t_img src, t_img dst, int x, int y)
{
	char	*onset;
	size_t	row;

	row = 0;
	onset = img_get_onset(src, x, y);
	while(row < dst.h)
	{
		img_cpy_line(onset, &(dst.addr[row * dst.length]), dst.length);
		onset += src.length;
		row++;
	}
}

t_img	img_extend(t_vars vars, t_img img, unsigned ratio)
{
	t_img 	new_img;
	size_t	row_new;
	size_t	col_new;
	size_t	row_old;
	size_t	col_old;
	size_t	i;

	row_new = 0;
	row_old = 0;
	new_img = new_image(vars, img.w * ratio, img.h * ratio);
	while (row_old < img.h)
	{
		while ((col_new + 1) % 3 != 0)
		{		
			while (col_old < img.w)
			{
				while ((col_new + 1) % 3 != 0)
					new_img.addr[col_new++] = img.addr[col_old];
				col_old++;
			}
			row_new++;
		}
		row_old++;
	}
	return (new_img);
}