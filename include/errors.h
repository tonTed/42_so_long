/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:00:36 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 22:26:11 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../libraries/libft/include/libft.h" 

#define ERR_MESS "Error\n"
#define ERR_AMOUNTS_ARG "Arguments expected: 1, given: "

int	err(void);

int	err_amount_args(int argc);

#endif