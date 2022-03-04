/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:24:43 by tonted            #+#    #+#             */
/*   Updated: 2022/03/03 21:07:18 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_next_move_valid_e(t_map *map, int step_x, int step_y)
{
	u_int32_t	i_data;

	i_data = get_pos_data_map(map->enemy.pos.x + step_x, map->enemy.pos.y
			+ step_y, map->w);
	if (map->data[i_data] == WALL_CHAR)
		return (false);
	return (true);
}
