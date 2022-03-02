/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:04:47 by tonted            #+#    #+#             */
/*   Updated: 2022/03/02 10:46:47 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define BPP 4
# define TITLE "so_long"
# define BLOC_SIZE 32
# define BLOC_LEN 128
# define COLOR_IGNORED 0x00FF00

/* WALL & FLOOR */
# define PATH_WF "./assets/walls.xpm"
# define SIZE_WF 16
# define RATIO_WF 2
# define PERIPH_WF 1
# define SEP_WF 4
# define WALL_X 1
# define WALL_Y 3
# define FLOOR_X 2
# define FLOOR_Y 1
# define EXIT_X 6
# define EXIT_Y 2

/* PLAYER */
# define PATH_P "./assets/doraemon.xpm"
# define SIZE_P 32
# define RATIO_P 1
# define PERIPH_P 1
# define SEP_P 1
# define PLAYER_X 3
# define PLAYER_Y 1

/* PLAYER TOP */
# define PLAYER_X_TOP 4
# define PLAYER_Y_TOP 1
/* PLAYER BOT */
# define PLAYER_X_BOP 1
# define PLAYER_Y_BOP 1
/* PLAYER LEFT */
# define PLAYER_X_LEFT 2
# define PLAYER_Y_LEFT 1
/* PLAYER RIGHT */
# define PLAYER_X_RIGHT 3
# define PLAYER_Y_RIGHT 1

/* COLLECTABLES */
# define PATH_C "./assets/collectables.xpm"
# define SIZE_C 16
# define RATIO_C 2
# define PERIPH_C 0
# define SEP_C 1
# define COLLEC_X 6
# define COLLEC_Y 8

typedef struct s_assets
{
	char	*wall;
	char	*floor;
	char	*item;
	char	*player;
	char	*p_top;
	char	*p_bot;
	char	*p_left;
	char	*p_right;
	char	*exit;
}			t_assets;

#endif
