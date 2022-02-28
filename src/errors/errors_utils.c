/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:20:35 by tonted            #+#    #+#             */
/*   Updated: 2022/02/27 18:44:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err(void)
{
	ft_putstr_fd(BRED ERR_MESS RESET, STDERR_FILENO);
	return (EXIT_FAILURE);
}
