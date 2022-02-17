/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:08:19 by tonted            #+#    #+#             */
/*   Updated: 2022/02/16 17:25:55 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

/*
** First pixel	-> line - 37		/ col - 1
** First line	-> line - 37 + 1	/ col - 1 + 1
** Separation	-> 4 pixels
** Size			-> 16 pixels
**	
**	Example		-> asset line 4, col 6
**	
**	>> x -> 1 + (6-1) * (16 + 4) =
**	>> y -> 1 + (4-1) * (16 + 4) = 
**
**
*/
# define WALLS_PATH "walls.xpm"

# define POS_LT_WALL_X 4
# define POS_LT_WALL_Y 18

#endif