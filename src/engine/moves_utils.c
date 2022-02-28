/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:47:24 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:49:47 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

u_int32_t	get_pos_data_map(u_int32_t x, u_int32_t y, u_int32_t width)
{
	return (y * width + x);
}

bool	cur_char(t_map map, char c)
{
	u_int32_t	i_cur;

	i_cur = get_pos_data_map(map.player.pos.x, map.player.pos.y, map.w);
	if (map.data[i_cur] == c)
		return (true);
	return (false);
}

bool	end_game(t_vars *vars)
{
	if (!vars->map.items && cur_char(vars->map, EXIT_CHAR))
		return (true);
	return (false);
}

bool	is_next_move_valid(t_map *map, int step_x, int step_y)
{
	u_int32_t	i_data;

	i_data = get_pos_data_map(map->player.pos.x + step_x, map->player.pos.y
			+ step_y, map->w);
	if (map->data[i_data] == WALL_CHAR)
		return (false);
	if (map->data[i_data] == ITEM_CHAR)
	{
		map->data[i_data] = EMPTY_CHAR;
		map->items--;
	}
	map->player.moves++;
	ft_putnbr_fd(map->player.moves, 1);
	ft_putendl_fd("", 1);
	return (true);
}
