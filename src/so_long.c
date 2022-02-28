/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:46 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 20:03:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(void *param)
{
	exit(free_exit(param, EXIT_SUCCESS));
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (err_amount_args(argc));
	if (read_map(argv[1], &vars))
		return (free_exit(&vars, EXIT_FAILURE));
	init_mlx_assets(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 8, 0, close_game, &vars);
	mlx_loop_hook(vars.mlx, draw_frame, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
