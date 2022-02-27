/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:46 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 11:27:17 by tonted           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_vars	vars;
	
	if (argc != 2)
		return (err_amount_args(argc));
	if (read_map(argv[1], &vars))
		return (free_exit(&vars, EXIT_FAILURE));
	init_mlx_assets(&vars);
	draw_frame(&vars);
	mlx_loop(vars.mlx);
	free_memory(&vars);
	return (EXIT_SUCCESS);
}
