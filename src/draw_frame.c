/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:26:54 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 17:53:32 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ignore_color(char *data)
{
	return (*(int *)data == COLOR_IGNORED);
}

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

void	set_bloc_by_line(t_img *display, char *src, unsigned pos_x, unsigned pos_y)
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
	unsigned len;

	len = 0;
	while (len < vars->map.w * vars->map.h)
	{
		if (vars->map.data[len] == WALL_CHAR)
		{
			set_bloc_by_line(&vars->display, vars->assets.wall,
				len % vars->map.w,
				len / vars->map.w);
		}
		else
		{
			set_bloc_by_line(&vars->display, vars->assets.floor,
				len % vars->map.w,
				len / vars->map.w);
			if (vars->map.data[len] == EXIT_CHAR)
				set_bloc_by_line(&vars->display, vars->assets.exit,
				len % vars->map.w,
				len / vars->map.w);
			else if (vars->map.data[len] == ITEM_CHAR)
			{
				set_bloc_by_line(&vars->display, vars->assets.item,
				len % vars->map.w,
				len / vars->map.w);
			}
		}
		len++;
	}
}

void	draw_player(t_vars *vars)
{
	set_bloc_by_line(&vars->display, vars->assets.player, vars->map.player.pos.x,
		vars->map.player.pos.y);
}

int	draw_frame(t_vars *vars)
{
	draw_background(vars);
	draw_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->display.ptr, 0, 0);
	return (EXIT_SUCCESS);
}
