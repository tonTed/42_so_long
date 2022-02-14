/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:35:37 by tonted            #+#    #+#             */
/*   Updated: 2022/02/14 15:07:09 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*img_get_onset(t_img img, int x, int y);
void	xpm_to_img(t_img src, t_img dst, int x, int y);

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
	vars->h = SIZE * rows;
	vars->w = SIZE * cols;
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
	int w = 0;
	int h = 0;

	img = new_image(vars, SIZE, SIZE);
	xpm = new_xpm(vars, "walls.xpm");

	// set_img_from_xpm(xpm, img, 1, 41);
	xpm_to_img(xpm, img, 1, 41);


	new_img = img_extend(vars, img, 3);
	mlx_put_image_to_window(vars.ptr, vars.win, new_img.ptr, 4, 5);
	mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, 54, 5);
	printf(">>> %d\n", img.length);

	printf("w: %d, h:%d\n", img.w, img.h);
	

	
	mlx_loop(vars.ptr);
	mlx_destroy_image(vars.ptr, xpm.ptr);
	mlx_destroy_image(vars.ptr, img.ptr);
	return (0);
}
