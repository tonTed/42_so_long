/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:10:18 by tonted            #+#    #+#             */
/*   Updated: 2022/03/03 21:10:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err_map_player(void)
{
	err();
	ft_putstr_fd(ERR_MAP_PLAYER, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	err_map_exit(void)
{
	err();
	ft_putstr_fd(ERR_MAP_EXIT, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	err_map_enemy(void)
{
	err();
	ft_putstr_fd(ERR_MAP_ENEMY, STDERR_FILENO);
	return (EXIT_FAILURE);
}
