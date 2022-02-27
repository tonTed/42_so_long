/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:04:11 by tonted            #+#    #+#             */
/*   Updated: 2022/02/26 10:55:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define WALL_CHAR '1'
# define ITEM_CHAR 'C'
# define PLAYER_CHAR 'P'
# define EXIT_CHAR 'E'
# define EMPTY_CHAR '0'
# define PLAYER_FLAG 0x1
# define EXIT_FLAG 0x2

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_player
{
	unsigned	moves;
	t_coord		pos;
}			t_player;

typedef struct s_map
{
	unsigned	w;
	unsigned	h;
	unsigned	len;
	ssize_t		items;
	char		*data;
	t_coord		exit;
	t_player	player;
}			t_map;