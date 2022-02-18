/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:11:20 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/18 11:56:54 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	0 pour un emplacement vide,
	1 pour un mur,
	C pour un item à ramasser (c pour collectible),
	E pour une sortie,
	P pour la position de départ du personnage.
	- La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas
		le cas, le programme retourne une erreur.
	- La carte doit contenir au moins une sortie, un item, et une position de
		départ.
	- La carte doit être de forme rectangulaire.
*/

int	set_map_size(t_vars *vars, int fd)
{
	char	*line;
	int		loop;

	loop = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		vars->h++;
	}

	free(line);
	return (EXIT_SUCCESS);
}

int	parse_file(t_vars *vars, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (err_open(strerror(errno), path));
	if (set_map_size(vars, fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	manage_input(t_vars *vars, int argc, const char **argv)
{
	if (argc != 2)
		return (err_argc_invalid(argc));
	if (parse_file(vars, argv[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}