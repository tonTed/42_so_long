/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:26:54 by tonted            #+#    #+#             */
/*   Updated: 2022/03/02 20:08:45 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_line_by_pixel(char *dst, char *src)
{
	size_t	col;

	col = 0;
	while (col < BLOC_SIZE)
	{
		if (!ignore_color(&src[col * BPP]))
			ft_memcpy(&dst[col * BPP], &src[col * BPP], BPP);
		col++;
	}
}

void	bloc_line(t_img *display, char *src, u_int32_t pos_x, u_int32_t pos_y)
{
	size_t	row;
	size_t	i_begin;

	row = 0;
	i_begin = display->length * pos_y * BLOC_SIZE + pos_x * BLOC_LEN;
	while (row < BLOC_SIZE)
	{
		set_line_by_pixel(&display->data[i_begin + row * display->length],
			&src[row * BLOC_LEN]);
		row++;
	}
}

void	draw_background(t_vars *vars)
{
	uint32_t	len;

	len = 0;
	while (len < vars->map.w * vars->map.h)
	{
		if (vars->map.data[len] == WALL_CHAR)
		{
			bloc_line(&vars->display, vars->assets.wall,
				len % vars->map.w, len / vars->map.w);
		}
		else
		{
			bloc_line(&vars->display, vars->assets.floor,
				len % vars->map.w, len / vars->map.w);
			if (vars->map.data[len] == EXIT_CHAR)
				bloc_line(&vars->display, vars->assets.exit,
					len % vars->map.w, len / vars->map.w);
			else if (vars->map.data[len] == ITEM_CHAR)
			{
				bloc_line(&vars->display, vars->assets.item,
					len % vars->map.w, len / vars->map.w);
			}
		}
		len++;
	}
}

void	draw_player(t_vars *vars)
{
	bloc_line(&vars->display, vars->assets.player,
		vars->map.player.pos.x, vars->map.player.pos.y);
}

int	draw_frame(t_vars *vars)
{
	draw_background(vars);
	draw_player(vars);
	counter(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->display.ptr, 0, 0);
	return (EXIT_SUCCESS);
}
