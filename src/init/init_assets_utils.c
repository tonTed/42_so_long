/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:22:16 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:38:58 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*alloc_asset(void)
{
	return ((char *)ft_calloc(BLOC_LEN * BLOC_SIZE, sizeof(char)));
}

u_int32_t	get_index_begin(u_int32_t pos_x, u_int32_t pos_y, t_xpm xpm)
{
	int	first_line_empty;
	int	first_col_empty ;
	int	lines_skiped;
	int	col_skiped;

	first_line_empty = xpm.periph * xpm.img.length;
	first_col_empty = xpm.periph * BPP;
	lines_skiped = (pos_y - 1) * (xpm.img.length * (xpm.size + xpm.sep));
	col_skiped = (pos_x - 1) * (BPP * (xpm.size + xpm.sep));
	return (first_line_empty + lines_skiped + first_col_empty + col_skiped);
}

static u_int32_t	get_index_dst(t_set_data cur_pos, u_int32_t ratio)
{
	return (BLOC_LEN * cur_pos.row_origin * ratio
		+ BLOC_LEN * cur_pos.row_new
		+ cur_pos.col_origin * ratio * BPP
		+ cur_pos.col_new * BPP);
}

static u_int32_t	get_index_src(t_set_data cur_pos, u_int32_t length)
{
	return (cur_pos.i
		+ cur_pos.row_origin * length
		+ cur_pos.col_origin * BPP);
}

void	set_data_pixel(t_set_data cur_pos, char *dst, t_xpm xpm)
{
	cur_pos.col_new = 0;
	while (cur_pos.col_new < xpm.ratio)
	{
		ft_memcpy(&dst[get_index_dst(cur_pos, xpm.ratio)],
			&xpm.img.data[get_index_src(cur_pos, xpm.img.length)],
			BPP);
		cur_pos.col_new++;
	}
}
