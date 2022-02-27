/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:23:18 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 16:37:01 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map(t_map map)
{
	size_t	i;

	i = 0;
	printf(BLU "map.w: %u\n" RESET, map.w);
	printf(BLU "map.h: %u\n" RESET, map.h);
	ft_putstr_fd(GRN "", STDOUT_FILENO);
	while (map.data[i])
	{
		ft_putchar_fd(map.data[i++], STDOUT_FILENO);
		if (i % map.w == 0)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	ft_putstr_fd(RESET "", STDOUT_FILENO);
}

void	put_player(t_player *player)
{
	printf("moves\t-> addr: %p - data: %d\n", &player->moves, player->moves);
	printf("pos\t-> addr: %p - data: x(%d)/y(%d)\n", &player->pos, player->pos.x, player->pos.y);
}
