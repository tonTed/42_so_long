/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:40:26 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/23 21:49:03 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map map)
{
	size_t	i;

	i = 0;
	ft_putstr_fd(GRN "", STDOUT_FILENO);
	while (map.data[i])
	{
		ft_putchar_fd(map.data[i++], STDOUT_FILENO);
		if (i % map.w == 0)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	ft_putstr_fd(RESET "", STDOUT_FILENO);
}