/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:13 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 21:56:32 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
# define MLX_IMAGE_H

typedef	struct s_img
{
	void		*ptr;
	char		*data;
	unsigned	bpp;
	unsigned	length;
	int			endian;
	unsigned	w;
	unsigned	h;
}			t_img;


#endif