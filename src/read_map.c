/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:30:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 11:00:43 by tonted           ###   ########.fr       */
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
		return (EXIT_FAILURE);
	if (is_valid_map(&vars->map))
		return (EXIT_FAILURE);
	vars->map.len = vars->map.w * vars->map.h;
	return (EXIT_SUCCESS);
}
