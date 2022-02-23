/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:30:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 16:49:46 by tblanco          ###   ########.fr       */
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
		printf(BLU "map.w: %u\n" RESET, map->w);
	return (EXIT_SUCCESS);
}

int	read_file(int fd, t_vars *vars)
{
	char	*line;

	if (init_map(&vars->map, fd))
		return (EXIT_FAILURE);
	printf("%s\n", vars->map.data);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != vars->map.w)
			return (err_map_w_len(line));
		printf("%s\n", line);
		// printf("%p\n", vars->map.data);
		// vars->map.data = ft_strjoin_free(vars->map.data, line);
		// printf("%p\n", vars->map.data);
		vars->map.h++;
	}
	if (DEBUG)
	{
		printf(BLU "map.h: %u\n" RESET, vars->map.h);
		// print_map(vars->map);
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
