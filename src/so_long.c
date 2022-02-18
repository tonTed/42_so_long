/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:07:45 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/18 10:49:00 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	manage_input(t_vars *vars, int argc, const char **argv);

int main(int argc, char const *argv[])
{
	t_vars	vars;

	if (manage_input(&vars, argc, argv))
		return (EXIT_FAILURE);
	return 0;
}
