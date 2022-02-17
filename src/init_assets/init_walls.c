/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:31:43 by tonted            #+#    #+#             */
/*   Updated: 2022/02/16 17:46:31 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "assets.h"

char	*set_data(t_img img, unsigned pos_x, unsigned pos_y)
{
	char	*ret;
	size_t	row;
	size_t	col;
	size_t	ratio;

	ret = (char *)malloc(sizeof(char) * BLOC_SIZE * _UNIQ_BPP);
	row = 0;
	while (row < ASSET_SIZE)
	{
		col = 0;
		while (col < BLOC_SIZE * _UNIQ_BPP)
		{
			ratio = 0;
			while (ratio < RATIO)
			{
				ft_memcpy(&ret[], &img.addr[], _UNIQ_BPP);
				ratio++;
			}
			col++;
		}
		row++;
	}


	return (ret);
}

bool	set_walls(t_vars vars)
{
	t_img	xpm_walls;
	
	xpm_walls = new_xpm(vars, WALLS_PATH);

	vars.ma.lt_wall = set_data(xpm_walls, POS_LT_WALL_X, POS_LT_WALL_Y);
}