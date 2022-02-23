/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:30:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 22:43:36 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_map(char *path, t_vars *vars)
{
	int	fd;

	if (open_file(path, &fd))
		return (err_open(strerror(errno), path));
	return (EXIT_SUCCESS);
}
