/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:30:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 09:00:58 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (err_open(strerror(errno), path));
	return (EXIT_SUCCESS);
}

int	init_map(t_map *map, int fd)
{
	map->h = 0;
	map->data = get_next_line(fd);
	map->w = ft_strlen(map->data);
	if (map->w < 3)
		return (err_map_w(map->w));
	if (DEBUG)
		printf("map.w: %u\n", map->w);
	return (EXIT_SUCCESS);
}

int	read_file(int fd, t_vars *vars)
{
	char	*line;

	if (init_map(&vars->map, fd));
		return (EXIT_FAILURE);
	while (42)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
	}
	return (EXIT_SUCCESS);
}

int	read_map(char *path, t_vars *vars)
{
	int	fd;

	if (open_file(path, &fd))
		return (EXIT_FAILURE);
	if (read_file(fd, vars))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
