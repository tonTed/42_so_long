/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 07:09:51 by tonted            #+#    #+#             */
/*   Updated: 2022/03/03 21:24:33 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_only_wall(char *line)
{
	while (*line)
		if (*line++ != WALL_CHAR)
			return (err_map_wall(NULL));
	return (EXIT_SUCCESS);
}

int	is_col_wall(char *line, size_t i_end)
{
	if (line[0] != WALL_CHAR || line[i_end] != WALL_CHAR)
		return (err_map_wall(line));
	return (EXIT_SUCCESS);
}

int	is_valid_char(char c, char *flag, t_map *map, u_int32_t len)
{
	if (c == PLAYER_CHAR)
	{
		if (PLAYER_FLAG & *flag)
			return (err_map_player());
		*flag |= PLAYER_FLAG;
		init_player(map, len);
	}
	else if (c == EXIT_CHAR)
	{
		if (EXIT_FLAG & *flag)
			return (err_map_exit());
		else
			*flag |= EXIT_FLAG;
	}
	else if (c == ENEMY_CHAR)
	{
		if (ENEMY_FLAG & *flag)
			return (err_map_exit());
		else
			*flag |= ENEMY_FLAG;
		init_enemy(map, len);
	}
	else
		return (err());
	return (EXIT_SUCCESS);
}

int	is_valid_map(t_map *map)
{
	u_int32_t	i;
	char		flag;

	map->enemy.exists = 0;
	map->items = 0;
	flag = 0x0;
	i = 0;
	while (map->data[i])
	{
		if (map->data[i] == EMPTY_CHAR || map->data[i] == WALL_CHAR)
			;
		else if (map->data[i] == ITEM_CHAR)
			map->items++;
		else if (is_valid_char(map->data[i], &flag, map, i))
			return (EXIT_FAILURE);
		i++;
	}
	if (flag < 0x3)
		return (err());
	return (EXIT_SUCCESS);
}
