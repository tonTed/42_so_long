/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:00:36 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 23:20:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../libraries/libft/include/libft.h" 

# define ERR_MESS "Error\n"
# define ERR_AMOUNTS_ARG "Arguments expected: 1, given: "
# define ERR_MAP_W "Widht must be bigger than 2, current is: "

int	err(void);

int	err_amount_args(int argc);
int	err_open(char *error, char *path);
int	err_map_w(unsigned w);

#endif