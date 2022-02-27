/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:46 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:18:48 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx_assets(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map.w * BLOC_SIZE,
		vars->map.h * BLOC_SIZE, TITLE);
	vars->display = new_image(vars->mlx, vars->map.w * BLOC_SIZE,
		vars->map.h * BLOC_SIZE);
	init_assets(vars);
}


int	close_game(void *param)
{
	exit(free_exit(param, EXIT_SUCCESS));
	return (0);
}

int	key_hook(int key, void *param)
{
	if (key == KEY_W)
		move_up(param);
	else if (key == KEY_S)
		move_down(param);
	else if (key == KEY_D)
		move_right(param);
	else if (key == KEY_A)
		move_left(param);
	else if (key == KEY_ESC)
		free_exit(param, EXIT_SUCCESS);
	if (end_game(param))
		close_game(param);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_vars	vars;
	
	if (argc != 2)
		return (err_amount_args(argc));
	if (read_map(argv[1], &vars))
		return (free_exit(&vars, EXIT_FAILURE));
	init_mlx_assets(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 8, NULL, close_game, &vars);
	mlx_loop_hook(vars.mlx, draw_frame, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
