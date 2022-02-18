/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:31:43 by tonted            #+#    #+#             */
/*   Updated: 2022/02/18 08:47:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "assets.h"

unsigned	get_index(unsigned pos_x, unsigned pos_y)
{
	return ();
}

char	*set_data(t_img img, unsigned pos_x, unsigned pos_y)
{
	char	*ret;
	size_t	row;
	size_t	col;
	size_t	ratio_col;
	size_t	ratio_row;
	size_t	count = 0;

	ret = (char *)malloc(sizeof(char) * BLOC_SIZE * _UNIQ_BPP * BLOC_SIZE);
	row = 0;
	while (row < ASSET_SIZE)
	{
		col = 0;
		while (col < ASSET_SIZE)
		{
			ratio_col = 0;
			while (ratio_col < RATIO)
			{
				ratio_row = 0;
				while (ratio_row < RATIO)
				{
					ft_memcpy(&ret[col*_UNIQ_BPP*ratio_col + row*_UNIQ_BPP*BLOC_SIZE*RATIO + ratio_row*_UNIQ_BPP],
					&img.addr[get_index(pos_x, pos_y) + col*_UNIQ_BPP + row*img.length], _UNIQ_BPP);
					count++;
					ratio_row++;
				}
				ratio_col++;
			}
			col++;
		}
		row++;
	}
	return (ret);
}

bool	set_walls(t_vars *vars)
{
	t_img	xpm_walls;
	
	printf("HERE!\n");
	xpm_walls = new_xpm(vars->ptr, WALLS_PATH);
	vars->ma.lt_wall = set_data(xpm_walls, POS_LT_WALL_X, POS_LT_WALL_Y);
	return (1);
}