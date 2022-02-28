/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:59:48 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:39:59 by tonted           ###   ########.fr       */
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

void	init_mlx_assets(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map.w * BLOC_SIZE,
			vars->map.h * BLOC_SIZE, TITLE);
	vars->display = new_image(vars->mlx, vars->map.w * BLOC_SIZE,
			vars->map.h * BLOC_SIZE);
	init_assets(vars);
}
