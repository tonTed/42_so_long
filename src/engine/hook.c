/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:32:24 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:34:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
