/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:48 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 17:21:17 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_map *map, int fd)
{
	map->h = 1;
	map->data = get_next_line(fd);
	map->w = ft_strlen(map->data);
	if (map->w < 3)
		return (err_map_w(map->w));
	return (EXIT_SUCCESS);
}

void	init_player(t_map *map, int len)
{
	map->player.pos.x = len % map->w;
	map->player.pos.y = len / map->w;
	map->player.moves = 0;
	map->data[len] = EMPTY_CHAR;
}
