/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:17:07 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:49:56 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (!is_next_move_valid(&vars->map, 0, -1))
		return ;
	vars->map.player.pos.y--;
}

void	move_down(t_vars *vars)
{
	if (!is_next_move_valid(&vars->map, 0, 1))
		return ;
	vars->map.player.pos.y++;
}

void	move_right(t_vars *vars)
{
	if (!is_next_move_valid(&vars->map, 1, 0))
		return ;
	vars->map.player.pos.x++;
}

void	move_left(t_vars *vars)
{
	if (!is_next_move_valid(&vars->map, -1, 0))
		return ;
	vars->map.player.pos.x--;
}
