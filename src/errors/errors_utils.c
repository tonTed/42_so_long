/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:20:35 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 11:31:32 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err()
{
	ft_putstr_fd(BRED ERR_MESS RESET, STDERR_FILENO);
	return (EXIT_FAILURE);
}
