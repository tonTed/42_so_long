/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:46 by tonted            #+#    #+#             */
/*   Updated: 2022/02/22 22:44:28 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_vars	vars;
	
	if (argc != 2)
		return (err_amount_args(argc));
	if (read_map(argv[1], &vars))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
