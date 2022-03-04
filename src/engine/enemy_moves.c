/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:24:43 by tonted            #+#    #+#             */
/*   Updated: 2022/03/04 08:10:55 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_enemy(t_vars *vars)
{
	if (!is_next_move_valid_e(&vars->map, 0, -1))
		return ;
	vars->map.enemy.pos.y--;
}

void	move_down_enemy(t_vars *vars)
{
	if (!is_next_move_valid_e(&vars->map, 0, 1))
		return ;
	vars->map.enemy.pos.y++;
}

void	move_right_enemy(t_vars *vars)
{
	if (!is_next_move_valid_e(&vars->map, 1, 0))
		return ;
	vars->map.enemy.pos.x++;
}

void	move_left_enemy(t_vars *vars)
{
	if (!is_next_move_valid_e(&vars->map, -1, 0))
		return ;
	vars->map.enemy.pos.x--;
}

void	move_enemy(t_vars *vars, int nb)
{
	static u_int32_t	rand = 0;
	static u_int32_t	i = 0;
	static u_int32_t	x = 0;
	u_int32_t			j;

	i++;
	rand += (vars->map.enemy.pos.x + i) * nb + vars->map.player.pos.y * nb * 7
		* i + vars->map.items * rand + i * rand % i + i;
	rand = (rand + 1) % 4;
	if (rand == 1)
		move_down_enemy(vars);
	else if (rand == 2)
		move_left_enemy(vars);
	else if (rand == 3)
		move_up_enemy(vars);
	else
		move_right_enemy(vars);
	if (is_player_on_enemy(vars->map, vars))
		close_game(vars);
	if (i % 2 == 0 && rand)
		i /= rand;
	else
		i += nb;
}
