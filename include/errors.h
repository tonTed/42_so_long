/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:00:36 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 19:57:15 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../libraries/libft/include/libft.h" 

# define ERR_MESS "Error\n"
# define ERR_AMOUNTS_ARG "Arguments expected: 1, given: "
# define ERR_MAP_W "Widht must be bigger than 2, current is: "
# define ERR_MAP_W_LEN "Map is not rectangular\n"
# define ERR_MAP_WALL "Map is not closed\n"
# define ERR_MAP_PLAYER "Amount of player must be 1.\n"
# define ERR_MAP_EXIT "Amount of exit must be 1.\n"

int	err(void);

int	err_amount_args(int argc);
int	err_open(char *error, char *path);
int	err_map_w(u_int32_t w);
int	err_map_w_len(char *line);
int	err_map_wall(char *line);
int	err_map_player(void);
int	err_map_exit(void);

#endif