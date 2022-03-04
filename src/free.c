/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:37:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/03/03 22:03:34 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_assets assets)
{
	u_int32_t	i;

	free(assets.wall);
	free(assets.exit);
	free(assets.floor);
	free(assets.p_bot);
	free(assets.p_top);
	free(assets.p_right);
	free(assets.p_left);
	i = 0;
	while (assets.items[i])
		free(assets.items[i++]);
	free(assets.items);
}

void	free_memory(t_vars *vars)
{
	free(vars->map.data);
	free_assets(vars->assets);
}

int	free_exit(t_vars *vars, int code_exit)
{
	exit(code_exit);
	return (code_exit);
}
