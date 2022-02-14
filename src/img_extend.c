/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:35:21 by tonted            #+#    #+#             */
/*   Updated: 2022/02/14 15:22:15 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*img_get_onset(t_img img, int x, int y)
{
	return ((char *)(img.addr + (y * img.length + x * (img.bpp / 8))));
}

void	img_cpy_line(char *src, char *dst, size_t len)
{
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

void	img_extend_step(char *src, char *dst, size_t steps, size_t ratio)
{
	size_t	i;

	i = 0;
	while (i < ratio)
	{
		printf("\t\tLoop: %zu - steps: %zu\n", i, steps);
		ft_memcpy(&dst[i++ * steps], src, steps);
	}
}

void	img_extend_line(t_img src, t_img dst, size_t ratio, size_t rows)
{
	size_t	i;
	size_t	j;
	size_t	step;

	j = 0;
	step = src.length / src.w;
	while(j < ratio)
	{
		i = 0;
		printf("Loop: %zu - ratio: %zu\n", j, ratio);
		while (i < src.w)
		{
			printf("\tLoop: %zu\n", i);
			img_extend_step(&src.addr[i * step + src.length], &dst.addr[i * step * ratio + dst.length * j], step, ratio);
			i++;
		}
		j++;
	}
}

t_img	img_extend(t_vars vars, t_img img, unsigned ratio)
{
	t_img 	new_img;
	size_t	rows;

	rows = 0;
	new_img = new_image(vars, img.w * ratio, img.h * ratio);
	// while (rows < img.h)
	// {
		img_extend_line(img, new_img, ratio, rows);
	// 	rows++;
	// }

	return (new_img);
}