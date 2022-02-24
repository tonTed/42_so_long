/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:46 by tonted            #+#    #+#             */
/*   Updated: 2022/02/23 21:59:45 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_exit(t_vars *vars, int code_exit)
{
	free_memory(vars);
	return (code_exit);
}

int main(int argc, char **argv)
{
	t_vars	vars;
	
	if (argc != 2)
		return (err_amount_args(argc));
	if (read_map(argv[1], &vars))
		return (free_exit(&vars, EXIT_FAILURE));
	free_memory(&vars);
	return (EXIT_SUCCESS);
}
