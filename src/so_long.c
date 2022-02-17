/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:35:37 by tonted            #+#    #+#             */
/*   Updated: 2022/02/17 12:34:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map(char *path, t_vars *vars)
{
	int		fd;
	size_t	rows;
	size_t	cols;
	char	*line;


	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(1);
	rows = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		cols = ft_strlen(line);
		free(line);	
	}
	vars->h = BLOC_SIZE * rows;
	vars->w = BLOC_SIZE * cols;
	close(fd);
	return(0);
}

void	set_img_from_xpm(t_img xpm, t_img img, int x, int y)
{
	char	*start;
	size_t	col;
	size_t	row;


	row = 0;
	start = img_get_onset(xpm, x, y);
	while (row < img.h)
	{
		col = 0;
		while (col < img.length)
		{
			img.addr[row * img.length + col] = start[col];
			col++;
		}
		row++;
		start += xpm.length;
	}
}

bool	set_walls(t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_img	xpm;
	t_img	img;
	t_img 	new_img;
	t_img	win_img;
	
	if (argc != 2)
		return (1);
	set_map(argv[1], &vars);

	vars.ptr = mlx_init();
	vars.title = argv[0];
	vars.win = mlx_new_window(vars.ptr, vars.w, vars.h, vars.title);

	win_img = new_image(vars, vars.w, vars.h);

	set_walls(&vars);
	ft_memcpy(&win_img.addr[0], vars.ma.lt_wall, BLOC_SIZE * _UNIQ_BPP * BLOC_SIZE);
	printf("HERE!\n");


	img = new_image(vars, 16, 16);
	xpm = new_xpm(vars, "./assets/walls.xpm");
	set_img_from_xpm(xpm, img, 1, 41);
	xpm_to_img(xpm, img, 61, 341);
	new_img = img_extend(vars, img, 3);
	mlx_put_image_to_window(vars.ptr, vars.win, win_img.ptr, 0, 0);

	// mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, 54, 5);
	mlx_loop(vars.ptr);
	return (0);
}
