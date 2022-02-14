/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:35:37 by tonted            #+#    #+#             */
/*   Updated: 2022/02/06 21:08:02 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"
#include "../mlx/mlx.h"
/*

int
mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
	
int
mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color,
				char *string );

int
mlx_loop ( void *mlx_ptr );

int
mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );


	void	*mlx_ptr;
	t_win	win;
	t_img	img;

	int		x;
	int		y;
	int		color;
	int		status;

	char	*filename;
	char	**data;
	char	*str;
	void	*(func_ptr)(int);
	void	*params;

	mlx_ptr = mlx_init();

	
	// win functions
	win.ptr = mlx_new_window(mlx_ptr, win.width, win.height, win.title);
	win.status = mlx_clear_window(mlx_ptr, win.ptr);
	win.status = mlx_destroy_window(mlx_ptr, win.ptr);

	// img functions
	img.ptr = mlx_new_image(mlx_ptr, img.width, img.height);
	status = mlx_put_image_to_window(mlx_ptr, win.ptr, img.ptr, x, y);
	img.status = mlx_destroy_image(mlx_ptr, img.ptr);
	img.ptr = mlx_xpm_to_image(mlx_ptr, data, img.width, img.height);
	img.ptr = mlx_xpm_file_to_image(mlx_ptr, filename, img.width, img.height);
	img.ptr = mlx_png_file_to_image(mlx_ptr, filename, img.width, img.height);

	mlx_hook(win.ptr, );
	mlx_key_hook(win.ptr, func_ptr, params);
	mlx_loop_hook(win.ptr, func_ptr, params);
	mlx_mouse_hook(win.ptr, func_ptr, params);
	mlx_expose_hook(win.ptr, func_ptr, params);
	
	mlx_string_put(mlx_ptr, win.ptr, x, y, color, str);
*/
/*

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
	while (1)
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

void	put_rect(t_vars vars, int x, int y, t_rect rect)
{
	int row = 0;
	int col = 0;
	
	while(row < SIZE)
	{
		col = 0;
		while(col < SIZE)
		{
			if (row != 0 || col != 0)
				mlx_pixel_put(vars.ptr, vars.win, x * SIZE + col, y * SIZE + row, rect.color);
			col++;
		}
		row++;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(int argc, char **argv)
{
	t_vars	vars;
	// int		x = 0;
	// int		y = 0;
	t_rect	rect;
	t_img	img;

	if (argc != 2)
		return (1);
	set_map(argv[1], &vars);

	rect.h = SIZE;
	rect.w = SIZE;
	rect.color = 0x00f39c12;
	vars.title = argv[1];
	vars.ptr = mlx_init();
	vars.win = mlx_new_window(vars.ptr, vars.w, vars.h, vars.title);
	img.w = 48;
	img.h = 48;
	img.ptr = mlx_new_image(vars.ptr, img.w, img.h);
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	int i = 0;
	while (i < img.h * img.w)
	{
		my_mlx_pixel_put(&img, i % SIZE, i / SIZE, rect.color * i / SIZE);
		i++;
	}
	mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, 0 , 0);
	mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, 0 + SIZE, 0);
	// img.ptr = mlx_xpm_file_to_image(img.ptr, "icon.png", &img.w, &img.h);


	// while (y <= vars.h / SIZE)
	// {
	// 	x = 0;
	// 	while (x <= vars.w / SIZE)
	// 	{
	// 		// put_rect(vars, x , y , rect);
	// 		// if (x == 0 || y == 0)
	// 			put_rect(vars, x, y, rect);
	// 			// mlx_put_image_to_window(vars.ptr, vars.win, img.ptr, x * SIZE, y * SIZE);
	// 		x++;
	// 	}
	// 	y++;
	// 	// printf("DEBUG\n");
	// }
	// mlx_pixel_put(vars.ptr, vars.win, 1, 1, rect.color);
	mlx_loop(vars.ptr);
	
	return (0);
}
*/