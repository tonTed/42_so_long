/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 07:09:51 by tonted            #+#    #+#             */
/*   Updated: 2022/02/25 20:52:53 by tonted           ###   ########.fr       */
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

int	is_valid_char(char c, char *flag)
{

	if (c == PLAYER_CHAR)
	{
		if (PLAYER_FLAG & *flag)
			return (err_map_player());
		else
			*flag |= PLAYER_FLAG;
	}
	else if (c == EXIT_CHAR)
	{
		if (EXIT_FLAG & *flag)
			return (err_map_exit());
		else
			*flag |= EXIT_FLAG;
	}
	else
		return (err());
	return (EXIT_SUCCESS);
}

int	is_valid_map(t_map *map)
{
	unsigned	i;
	char		flag;

	map->items = 0;
	flag = 0x0;
	while (map->data[i])
	{
		if (map->data[i] == EMPTY_CHAR || map->data[i] == WALL_CHAR)
			;
		else if (map->data[i] == ITEM_CHAR)
			map->items++;
		else if (is_valid_char(map->data[i], &flag))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}