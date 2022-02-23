/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:16:23 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 22:28:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err_amount_args(int argc)
{
	err();
	ft_putstr_fd(ERR_AMOUNTS_ARG, STDERR_FILENO);
	ft_putnbr_fd(argc - 1, STDERR_FILENO);
	ft_putendl_fd(".", STDERR_FILENO);
	return (EXIT_FAILURE);
}