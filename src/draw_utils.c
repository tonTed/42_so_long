/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:30:14 by tonted            #+#    #+#             */
/*   Updated: 2022/03/03 16:10:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ignore_color(char *data)
{
	return (*(int *)data == COLOR_IGNORED);
}

void	display_move(t_vars *vars)
{
	char	*moves;

	moves = ft_itoa(vars->map.player.moves);
	mlx_string_put(vars->mlx, vars->win, 8, vars->map.h * BLOC_SIZE - 14,
		COLOR_STR, MOVE_STR);
	mlx_string_put(vars->mlx, vars->win, 64, vars->map.h * BLOC_SIZE - 14,
		COLOR_STR, moves);
	free(moves);
}
