/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables_animation_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:13:16 by tonted            #+#    #+#             */
/*   Updated: 2022/03/02 20:28:09 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_asset(t_vars *vars)
{
	static u_int32_t	i_asset = 0;

	if (i_asset < COLLEC_TOTAL - 1)
		i_asset++;
	else
		i_asset = 0;
	vars->assets.item = vars->assets.items[i_asset];
}

void	counter(t_vars *vars)
{
	static u_int32_t	count = 0;

	if (count++ == 10)
	{
		change_asset(vars);
		count = 0;
	}
}
