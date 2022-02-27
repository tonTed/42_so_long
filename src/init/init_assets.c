/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:27:47 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 12:36:44 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		set_data(t_xpm xpm, char **dst, unsigned pos_x, unsigned pos_y)
{
	t_set_data	cur_pos;

	cur_pos.i = get_index_begin(pos_x, pos_y, xpm);
	cur_pos.row_origin = 0;
	(*dst) = alloc_asset(); 
	while (cur_pos.row_origin < xpm.size)
	{
		cur_pos.col_origin = 0;	
		while (cur_pos.col_origin < xpm.size)
		{
			cur_pos.row_new = 0;
			while (cur_pos.row_new < xpm.ratio)
			{
				set_data_pixel(cur_pos, (*dst), xpm);
				cur_pos.row_new++;
			}
			cur_pos.col_origin++;
		}
		cur_pos.row_origin++;
	}
}

void		init_assets(t_vars *vars)
{
	t_xpm	wall;
	t_xpm	player;
	t_xpm	collec;

	wall = new_xpm(vars->mlx, PATH_WF, RATIO_WF);
	set_xpm(&wall, PERIPH_WF, SEP_WF, SIZE_WF);
	set_data(wall, &vars->assets.wall, WALL_X, WALL_Y);
	set_data(wall, &vars->assets.floor, FLOOR_X, FLOOR_Y);
	set_data(wall, &vars->assets.exit, EXIT_X, EXIT_Y);

	player = new_xpm(vars->mlx, PATH_P, RATIO_P);
	set_xpm(&player, PERIPH_P, SEP_P, SIZE_P);
	set_data(player, &vars->assets.player, PLAYER_X, PLAYER_Y);

	collec = new_xpm(vars->mlx, PATH_C, RATIO_C);
	set_xpm(&collec, PERIPH_C, SEP_C, SIZE_C);
	set_data(collec, &vars->assets.item, COLLEC_X, COLLEC_Y);

	mlx_destroy_image(vars->mlx, wall.img.ptr);
	mlx_destroy_image(vars->mlx, player.img.ptr);
}
