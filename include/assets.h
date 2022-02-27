/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:04:47 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 09:02:11 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BPP 4
# define TITLE "so_long"
# define BLOC_SIZE 32
# define BLOC_LEN BLOC_SIZE * BPP
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
	char	*exit;
}			t_assets;
