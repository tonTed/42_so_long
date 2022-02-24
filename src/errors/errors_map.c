/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:10:18 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 22:10:18 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err_map_w(unsigned w)
{
	err();
	ft_putstr_fd(ERR_MAP_W, STDERR_FILENO);
	ft_putnbr_fd(w, STDERR_FILENO);
	ft_putendl_fd(".", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	err_map_w_len(char *line)
{
	err();
	ft_putstr_fd(ERR_MAP_W_LEN, STDERR_FILENO);
	free(line);
	return (EXIT_FAILURE);
}

int	err_map_wall(char *line)
{
	err();
	ft_putstr_fd(ERR_MAP_WALL, STDERR_FILENO);
	if (!line)
		free (line);
	return (EXIT_FAILURE);
}
