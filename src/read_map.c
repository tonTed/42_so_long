/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:30:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 22:51:54 by tonted           ###   ########.fr       */
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
	map->h = 1;
	map->data = get_next_line(fd);
	map->w = ft_strlen(map->data);
	if (map->w < 3)
		return (err_map_w(map->w));
	if (DEBUG)
		printf(BLU "map.w: %u\n" RESET, map->w);
	return (EXIT_SUCCESS);
}

char	*data_concat_free(char *s1, char *s2, size_t len)
{
	char	*ret;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len_s1 + len + 1));
	ft_memcpy(ret, s1, len_s1);
	ft_memcpy(&ret[len_s1], s2, len);
	ret[len_s1 + len] = '\0';
	free(s1);
	free(s2);
	return (ret);
}

int		is_only_wall(char *line)
{
	while (*line)
		if (*line++ != WALL_CHAR)
			return (err_map_wall(NULL));
	return (EXIT_SUCCESS);
}

int		is_col_wall(char *line, size_t i_end)
{
	if (line[0] != WALL_CHAR || line[i_end] != WALL_CHAR)
		return (err_map_wall(line));
	return (EXIT_SUCCESS);
}

size_t	get_last_line(t_vars *vars)
{
	return ((vars->map.h - 1) * vars->map.w - 1);
}

int	read_file(int fd, t_vars *vars)
{
	char	*line;

	if (init_map(&vars->map, fd) || is_only_wall(vars->map.data))
		return (EXIT_FAILURE);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) != vars->map.w)
			return (err_map_w_len(line));
		if (is_col_wall(line, vars->map.w - 1))
			return (EXIT_FAILURE);
		vars->map.data =  data_concat_free(vars->map.data, line, vars->map.w);
		vars->map.h++;
	}
	if (is_only_wall(&vars->map.data[get_last_line(vars)]))
		return (EXIT_FAILURE);
	if (DEBUG)
	{
		printf(BLU "map.h: %u\n" RESET, vars->map.h);
		print_map(vars->map);
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
