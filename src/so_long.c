/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:35:37 by tonted            #+#    #+#             */
/*   Updated: 2022/02/16 17:26:44 by tonted           ###   ########.fr       */
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


int	main(int argc, char **argv)
{
	t_vars	vars;
	t_img	xpm;
	t_img	img;
	t_img new_img;

	if (argc != 2)
		return (1);
	set_map(argv[1], &vars);

	vars.ptr = mlx_init();
	vars.title = argv[0];
	vars.win = mlx_new_window(vars.ptr, vars.w, vars.h, vars.title);

	img = new_image(vars, 16, 16);
	xpm = new_xpm(vars, "walls.xpm");

	set_img_from_xpm(xpm, img, 1, 41);
	xpm_to_img(xpm, img, 61, 341);



	new_img = img_extend(vars, img, 3);
	printf("%d\n", img.length);
	printf("%d\n", new_img.length);
	mlx_put_image_to_window(vars.ptr, vars.win, new_img.ptr, 4, 5);
	mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, 54, 5);
	mlx_loop(vars.ptr);
	return (0);
}
