/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:53:53 by tonted            #+#    #+#             */
/*   Updated: 2022/02/16 16:24:59 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_cpy_line(char *src, char *dst, size_t len)
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
