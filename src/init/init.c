/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:48 by tonted            #+#    #+#             */
/*   Updated: 2022/02/25 21:00:01 by tonted           ###   ########.fr       */
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
	if (DEBUG)
		printf(BLU "map.w: %u\n" RESET, map->w);
	return (EXIT_SUCCESS);
}
