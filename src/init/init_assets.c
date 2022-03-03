/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:27:47 by tonted            #+#    #+#             */
/*   Updated: 2022/03/02 20:23:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_data(t_xpm xpm, char **dst, u_int32_t pos_x, u_int32_t pos_y)
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

void	set_player_assets(t_vars *vars)
{
	t_xpm	player;

	player = new_xpm(vars->mlx, PATH_P, RATIO_P);
	set_xpm(&player, PERIPH_P, SEP_P, SIZE_P);
	set_data(player, &vars->assets.p_top, PLAYER_X_TOP, PLAYER_Y_TOP);
	set_data(player, &vars->assets.p_bot, PLAYER_X_BOP, PLAYER_Y_BOP);
	set_data(player, &vars->assets.p_left, PLAYER_X_LEFT, PLAYER_Y_LEFT);
	set_data(player, &vars->assets.p_right, PLAYER_X_RIGHT, PLAYER_Y_RIGHT);
	vars->assets.player = vars->assets.p_right;
	mlx_destroy_image(vars->mlx, player.img.ptr);
}

void	set_collec_assets(t_vars *vars)
{
	t_xpm		collec;
	u_int32_t	i;

	collec = new_xpm(vars->mlx, PATH_C, RATIO_C);
	set_xpm(&collec, PERIPH_C, SEP_C, SIZE_C);
	vars->assets.items = (char **)malloc(sizeof(char *) * (COLLEC_TOTAL + 1));
	vars->assets.items[COLLEC_TOTAL] = NULL;
	i = 0;
	while (i < COLLEC_TOTAL)
	{
		set_data(collec, &vars->assets.items[i], i + 1, 1);
		i++;
	}
	vars->assets.item = vars->assets.items[0];
	mlx_destroy_image(vars->mlx, collec.img.ptr);
}

void	init_assets(t_vars *vars)
{
	t_xpm	wall;

	wall = new_xpm(vars->mlx, PATH_WF, RATIO_WF);
	set_xpm(&wall, PERIPH_WF, SEP_WF, SIZE_WF);
	set_data(wall, &vars->assets.wall, WALL_X, WALL_Y);
	set_data(wall, &vars->assets.floor, FLOOR_X, FLOOR_Y);
	set_data(wall, &vars->assets.exit, EXIT_X, EXIT_Y);
	mlx_destroy_image(vars->mlx, wall.img.ptr);
	set_player_assets(vars);
	set_collec_assets(vars);
}
